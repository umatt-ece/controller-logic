import elementtree.ElementTree as ET
import binascii
import struct
import sys
import os
import time

# If a file name was provided via command line
if (len(sys.argv) > 1):
	xmlfile = sys.argv[1]
	if(os.path.isfile(xmlfile) == False):
		print "\n    ERROR: File ",xmlfile," was not found, aborting..."
		sys.exit()
else:
	print "\n    ERROR: No input XML file was specified, aborting..."
	sys.exit()

################################		
# PYTHON SCRIPT CONSTANTS
################################		
ObjIDStrLen = 60       # Max Length of object ID C Macro line
ScriptVersion = "0.01" # Version of this script

def ObjectID_C_Macro(inputString, objectIDstring):
	instring = inputString.upper()
	outstring = "#define ISO_OBJECTID_"
	for chr in instring: # Loop through every character in the string:
		if (65 <= ord(chr) <= 90) or (48 <= ord(chr) <= 57): # IF character is a letter or a number
			outstring += chr
		else: # NOT a letter or number
			outstring += "_"
	objectIDNumberString = str(int(objectIDstring)) # Convert to int and back to string to remove leading zeros
	outstring += "_" + objectIDNumberString  # Add _objectID to the end of the string:
	spacesneeded = ObjIDStrLen - len(outstring) - len(objectIDNumberString)
	if (spacesneeded < 1):
		print "ERROR! Object ID String Length (ObjIDStrLen) is too small!!!!\n\n"
	outstring += (" " * spacesneeded) + objectIDNumberString
	return outstring
	
def PythonArrayToCArrayString(array):
	return "{" + ",".join(array) + "}"

def StringToRAWString(string):
	outstring = ""
	for chr in string:
		outstring = outstring + "'" + chr + "'" + ","
	return outstring	

def DecDigitToHexString(value):
	return "0x" + format(int(value), '02X')
	
def HexByteArray(hexstring):
	output = []
	for i in range(len(hexstring) / 2):
		output.append("0x" + (hexstring[i*2:(i*2)+2]).upper())  
	return output
  
def SignedHexString(value, numbytes):
	return format(value & (pow(256,numbytes)-1), '0'+str(numbytes*2)+'X')

class ObjAttributeType:
	NULL = 0
	String = 1
	WSM_NAME = 2
	ByteArray = 3
	Base10Float = 4
	Base10Unsigned = 5
	Base16Unsigned = 6
	Base10Signed = 7

class ObjAttribute:
	
	def __init__(self, Name, Type, Size, Value):
		self.Name = Name
		self.Type = Type
		self.Size = Size
		self.Value = Value
		self.RAW = []
		################################		
		# String
		################################		
		if(Type == ObjAttributeType.String):
			for chr in Value:
				self.RAW.append("'" + chr + "'")
		################################
		# ByteArray or WSM_NAME
		################################		
		elif(Type == ObjAttributeType.ByteArray or Type == ObjAttributeType.WSM_NAME):
			self.RAW += HexByteArray(Value)
		################################
		# Base10Float
		################################
		elif(Type == ObjAttributeType.Base10Float):
			BigEndianHexString = binascii.b2a_hex(struct.pack('f',float(Value)))
			self.RAW += HexByteArray(BigEndianHexString)
		################################
		# Base10Unsigned
		################################		
		elif(Type == ObjAttributeType.Base10Unsigned):
			for i in range(self.Size):
				self.RAW.append("0x" + format(int(Value) >> (i*8) & 0xFF, '02X'))
		################################
		# Base10Signed
		################################		
		elif(Type == ObjAttributeType.Base10Signed):
			HexString = format(int(Value) & (pow(256,Size)-1), '0'+str(Size*2)+'X')
			for i in range(len(HexString)-2, -1, -2):
				self.RAW.append("0x" + HexString[i:i+2])
		################################
		# Base16Unisgned
		################################		
		elif(Type == ObjAttributeType.Base16Unsigned):
			if (len(Value) != 2*Size):
				print "ERROR: String length is not the correct length! Length = ", len(Value), " Size = ", Size
			val = Value.upper() # Convert to upper case
			for i in range(len(val)-2, -1, -2):
				self.RAW.append("0x" + val[i:i+2])
	def GetName(self):
		return self.Name
	def RAWData(self):
		return self.RAW
	def LengthRAW(self): # Returns a 1 byte hex string representing the length of the RAW data array
		return ["0x" + format(int(len(self.RAW)), '02X')]
	def GetValue(self):
		return self.Value

NullObj = ObjAttribute("",ObjAttributeType.NULL, 0,"")		
		
class DDObject:
	
	def __init__(self, Name, A=NullObj, B=NullObj, C=NullObj, D=NullObj, E=NullObj, F=NullObj, G=NullObj):
		self.Name = Name
		self.Attributes = []
		self.RAW = []
		self.Error = [0]
		self.ReferencedObjects = []
		self.WSMNameOffset = 0
		self.StructureLabel = []
		self.StructureLabelOffset = 0
		self.A = A
		self.B = B
		self.C = C
		self.D = D
		self.E = E
		self.F = F
		self.G = G
		self.ObjectID_C_Macro = ""
		self.ObjectID = 0xFFFF # 0xFFFF = NULL Object ID defined by ISO 11783

	def GetAttribute(self, attribute_letter):
		if (attribute_letter.upper() == "A"):
			return self.A.GetValue()
		elif (attribute_letter.upper() == "B"):
			return self.B.GetValue()
		elif (attribute_letter.upper() == "C"):
			return self.C.GetValue()
		elif (attribute_letter.upper() == "D"):
			return self.D.GetValue()
		elif (attribute_letter.upper() == "E"):
			return self.E.GetValue()
		elif (attribute_letter.upper() == "F"):
			return self.F.GetValue()
		elif (attribute_letter.upper() == "G"):
			return self.G.GetValue()
		else:
			return 0
	def GetObjectID(self):
		if   (self.Name == "DVC"):
			self.ObjectID = 0
		elif (self.Name == "DET"):
			self.ObjectID = self.B.Value
		elif (self.Name == "DPD"):
			self.ObjectID = self.A.Value
		elif (self.Name == "DPT"):                                 
			self.ObjectID = self.A.Value
		elif (self.Name == "DVP"):                                 
			self.ObjectID = self.A.Value
		elif (self.Name == "DOR"):
			self.ObjectID = "DOR"
		else:
			self.ObjectID = 0xFFFF
		return self.ObjectID
		
	# Public function generates the C language MACRO representing the object ID
	def GetObjectID_C_Macro(self):
		if   (self.Name == "DVC"):
			self.ObjectID_C_Macro = ObjectID_C_Macro(self.B.Value, "0")
		elif (self.Name == "DET"):
			self.ObjectID_C_Macro = ObjectID_C_Macro(self.D.Value, self.B.Value)
		elif (self.Name == "DPD"):
			self.ObjectID_C_Macro = ObjectID_C_Macro(self.E.Value, self.A.Value)
		elif (self.Name == "DPT"):                                 
			self.ObjectID_C_Macro = ObjectID_C_Macro(self.D.Value, self.A.Value)
		elif (self.Name == "DVP"):                                 
			self.ObjectID_C_Macro = ObjectID_C_Macro(self.E.Value, self.A.Value)
		elif (self.Name == "DOR"):
			self.ObjectID_C_Macro = "DOR"
		else:
			self.ObjectID_C_Macro = "ERROR: Invalid Object Type: " + self.Name
		return self.ObjectID_C_Macro
		
	def GetErrors(self):
		return self.Error
		
	def AddRef(self,attr):
		self.ReferencedObjects.append(attr)
		
	def GetReferencedObjectIds(self):
		ReferencedObjectIds = []
		for attribute in self.ReferencedObjects:
			if (attribute.Name == "DeviceObjectId"):
				ReferencedObjectIds.append(attribute.Value)
		return ReferencedObjectIds
		
	def AddAttribute(self, attr):
		self.Attributes.append(attr)
			
# // If this structure changes, the python script that generates the object pool will need to be changed to match it.
# typedef struct TC_PDV_S
# {
  # uint16_t                ObjectID;
  # uint16_t                ElementNumber;  
  # uint16_t                DDI;
  # DPD_Properties_T        Properties;
  # TC_PDVTriggerMethod_T   Triggermethod;
  # Time_T                  SendInterval;
  # int32_t                 DistanceInterval;  
  # int32_t                 LastSentAtDistance;
  # SoftwareTimer_T         SendTimer;
  # int32_t                 MaxThreshold;
  # int32_t                 MinThreshold;
  # int32_t                 ChangeThreshold;
  # bool_t                  ValueChangedFlag;  
  # TC_Measurement_T        Measurement;
  # uint32_t                PDV_Value;
  # struct TC_PDV_S         *NextInList;
# }TC_PDV_T;	

	# generate C code for the PDV
	def GetPDVCCode(self, ElementNum):
		code = []
		code.append(self.A.Value)              # ObjectID
		code.append(str(ElementNum))           # ElementNumber
		code.append(str(int(self.B.Value,16))) # DDI
		if((int(self.C.Value) & 3) == 3):                              # If bit 0 = 1 && bit 1 = 1:
			code.append("DPD_PROPERTY_SETTABLE | DPD_PROPERTY_DEFAULT") #    Properties = 3
		elif((int(self.C.Value) & 2) == 2):                            # Else if bit 1 = 1:
			code.append("DPD_PROPERTY_SETTABLE")                        #    Properties = 2
		elif((int(self.C.Value) & 1) == 1):                            # Else if bit 0 = 1:
			code.append("DPD_PROPERTY_DEFAULT")                         #    Properties = 1
		else:                                                          # Else it's neither default or settable
			code.append("DPD_PROPERTY_NONE")                            #    Properties = 0
		# DETERMINE SUPPORTED TRIGGER METHODS:
		triggermethods = []
		if((int(self.D.Value) & 1) > 0):
			triggermethods.append("TRIGGER_METHOD_TIME")
		if((int(self.D.Value) & 2) > 0):
			triggermethods.append("TRIGGER_METHOD_DISTANCE")
		if((int(self.D.Value) & 4) > 0):
			triggermethods.append("TRIGGER_METHOD_THRESHOLD_LIMITS")
		if((int(self.D.Value) & 8) > 0):
			triggermethods.append("TRIGGER_METHOD_ONCHANGE")
		if((int(self.D.Value) & 16) > 0):
			triggermethods.append("TRIGGER_METHOD_TOTAL")	
		if(int(self.D.Value) == 0):
			triggermethods.append("TRIGGER_METHOD_NONE")
		code.append(" | ".join(triggermethods)) # Triggermethod
		code.append("0")                        # SendInterval
		code.append("0")                        # DistanceInterval
		code.append("0")						       # LastSentAtDistace
		code.append("MAKE_SoftwareTimer_T()")   # SendTimer
		code.append("0")                        # MaxThreshold
		code.append("0")                        # MinThreshold
		code.append("0")                        # ChangeThreshold
		code.append("FALSE")                    # ValueChangeFlag
		code.append("{NULL,NULL}")              # Measurement
		code.append("0")                        # PDV_Value
		code.append("NULL")                     # *NextInList;
		return "{" + ",".join(code) + "}"
		
	def GetRAWData(self):
		self.RAW = [] # reset 
		if (self.Name == "DVC"):
			if (1): #Ensure all attributes are present #THIS NEEDS TO BE DETERMINED!!!!!!!!!!!!!!
				self.RAW += ["'D'","'V'","'C'","0x00","0x00"] # Table ID + Object ID (Always 0 for DVC)
				self.RAW += self.B.LengthRAW() # Length of Designator
				self.RAW += self.B.RAWData()   # Device Designator
				self.RAW += self.C.LengthRAW() # Length of SW Version
				self.RAW += self.C.RAWData()   # SW Version
				self.WSMNameOffset = len(self.RAW)
				self.RAW += self.D.RAWData() # WSM NAME
				self.RAW += self.E.LengthRAW() # Length of Device Serial Number
				self.RAW += self.E.RAWData() #Serial #
				self.StructureLabelOffset = len(self.RAW)
				self.RAW += self.F.RAWData() #Structure Label
				self.StructureLabel = self.F.RAWData()
				if (len(self.G.RAWData()) == 7):
					self.RAW += self.G.RAWData() #Localization label
				else:
					self.RAW += self.G.RAWData()[:-1] #Localization label
			else:
				self.Error[0] = 1
				self.Error.append("Incomplete DVC")
		elif (self.Name == "DET"):
			if (1): #Ensure all attributes are present
				self.RAW += ["'D'","'E'","'T'"]
				self.RAW += self.B.RAWData() # ObjectID
				self.RAW += self.C.RAWData() # Element Type
				self.RAW += self.D.LengthRAW()# Number of Designator Bytes
				self.RAW += self.D.RAWData() # Designator
				self.RAW += self.E.RAWData() # Element Number
				self.RAW += self.F.RAWData() # Parent Object ID
				self.RAW += ["0x" + format(int(len(self.ReferencedObjects)) & 0xFF, '02X')] # Number of objects to follow, LSB
				self.RAW += ["0x" + format(int(len(self.ReferencedObjects)) >> 8 & 0xFF, '02X')] # Number of objects to follow, MSB
				for ref in self.ReferencedObjects:
					self.RAW += ref.RAWData() # List of references to DeviceProcessDataObjects or DevicePropertyObjects
			else:
				self.Error[0] = 1
				self.Error.Append("Incomplete DET")

		elif (self.Name == "DPD"):
			if (1): # Ensure all attributes are present
				self.RAW += ["'D'","'P'","'D'"]
				self.RAW += self.A.RAWData() # ObjectID
				self.RAW += self.B.RAWData() # Process Data DDI
				self.RAW += self.C.RAWData() # Process Data Properties
				self.RAW += self.D.RAWData() # Process Data Available Trigger Methods
				self.RAW += self.E.LengthRAW() # Number of designator bytes
				self.RAW += self.E.RAWData() # Process Data Designator
				if (self.F != NullObj): # If DVP exists for this item
					self.RAW += self.F.RAWData() # Device Value Presentation Object ID
				else:
					self.RAW += ["0xFF","0xFF"] # Add Null Object ID
			else:
				self.Error[0] = 1
				self.Error.append("Incomplete DPD")
				
		elif (self.Name == "DPT"):
			if (1): # Ensure all attributes are present
				self.RAW += ["'D'","'P'","'T'"]
				self.RAW += self.A.RAWData() # ObjectID
				self.RAW += self.B.RAWData() # Process Data DDI
				self.RAW += self.C.RAWData() # Device Property Value
				self.RAW += self.D.LengthRAW() # Number of designator bytes
				self.RAW += self.D.RAWData() # Property Designator
				if (self.E != NullObj): # If DVP exists for this item
					self.RAW += self.E.RAWData() # Device Value Presentation Object ID
				else:
					self.RAW += ["0xFF","0xFF"] # Add Null Object ID
			else:
				self.Error[0] = 1
				self.Error.append("Incomplete DPT")
		elif (self.Name == "DVP"):
			if (1): # Ensure all attributes are present
				self.RAW += ["'D'","'V'","'P'"]
				self.RAW += self.A.RAWData() # ObjectID
				self.RAW += self.B.RAWData() # Offset
				self.RAW += self.C.RAWData() # Scale
				self.RAW += self.D.RAWData() # Number of Decimals
				self.RAW += self.E.LengthRAW() # Number of UnitDesignator bytes
				self.RAW += self.E.RAWData() # UnitDesignator
			else:
				self.Error[0] = 1
				self.Error.Append("Incomplete DVP")		

		return self.RAW

class DDOP:

	def __init__(self):
		self.DDObjects = []
		self.CCode = ""
		self.ErrorList = []
		self.WSMNameOffset = []
		self.StructureLabelOffset = []
		self.StructureLabel = []
		
	def AddObject(self, DDObject):
		self.DDObjects.append(DDObject)
		
	def GenerateCCode(self):
	
		ErrorCount = 0 # Reset error count
		self.CCode = "" # Clear buffer
		ObjectNames = []
		PDVList = [] # list of DPDs in the DDOP
		DPD_ObjectID_C_Macros = [] # list of #define C macros for DPD objects
		nonDPD_ObjectID_C_Macros = [] # list of #define C macros for non-DPD objects
		TotalPoolSize = 1 # Start at 1 to account for the first byte (0x51)of the object pool transfer message added to the first object
		
		self.CCode += "//  ----------------------------------------------\n"
		self.CCode += "//      ____     ____  _____  ______          __\n"
		self.CCode += "//     / __ \   /  _/ / ___/ /_  __/  ___    / /__\n"
		self.CCode += "//    / / / /   / /   \__ \   / /    / _ \  / //_/\n"
		self.CCode += "//   / /_/ /   / /   ___/ /  / /    /  __/ / ,<\n"
		self.CCode += "//  /_____/  _/ /   /____/  /_/     \___/ /_/|_|\n"
		self.CCode += "//          /___/ ntegration, Inc. Copyright (C) 2014\n" 
		self.CCode += "//  ----------------------------------------------\n"
		self.CCode += "//  This file was auto-generated via Python script\n"
		self.CCode += "//  ----------------------------------------------\n"
		self.CCode += "//    XML File:       " + xmlfile + "\n"
		self.CCode += "//    Script File:    " + os.path.basename(__file__) + "\n"
		self.CCode += "//    Script Version: " + ScriptVersion + "\n"
		self.CCode += "//    Date:           " + time.strftime("%d-%b-%Y").upper() + "\n"
		self.CCode += "//    Time:           " + time.strftime("%H:%M:%S")
		self.CCode += "//\n"
		self.CCode += "//  ----------------------------------------------\n"
		self.CCode += "\n\n"
		self.CCode += "/*************************************************/\n/*\n"
		self.CCode += "   PROCESS DATA VARIABLE STRUCTURES:"		
		self.CCode += "\n*/\n/*************************************************/\n"
		
		# Loop through every object
		for index,obj in enumerate(self.DDObjects):
			ObjectName = "Object" + str(index + 1)
			ObjectNames.append(ObjectName)
			if(index == 0):
				self.CCode += "const unsigned char " + ObjectName + "[] = " + PythonArrayToCArrayString(["0x61"] + obj.GetRAWData()) + ";\n"
			else:
				self.CCode += "unsigned char " + ObjectName + "[] = " + PythonArrayToCArrayString(           obj.GetRAWData()) + ";\n"
			TotalPoolSize += len(obj.GetRAWData())
			if (obj.WSMNameOffset > 0):
				self.WSMNameOffset = [index, obj.WSMNameOffset]
			if (obj.StructureLabelOffset > 0):
				self.StructureLabel = obj.StructureLabel
				self.StructureLabelOffset = [index, obj.StructureLabelOffset]
			if(obj.GetErrors()[0] > 0):
				ErrorCount += obj.GetErrors()[0]
				self.ErrorList.append(obj.GetErrors()[1:])
			if(obj.Name == "DPD"):
				# This loop finds the element number of the parent DET object
				ParentElementNum = -1
				for index_again,obj_again in enumerate(self.DDObjects):
					if(obj_again.Name == "DET"):
						for referenced_id in obj_again.GetReferencedObjectIds():
							if (referenced_id == obj.GetObjectID()):
								#print "ObjID = ",obj.GetObjectID(),"ParentObjectID = ",obj_again.GetObjectID(),"Element#",obj_again.GetAttribute("E")
								ParentElementNum = obj_again.GetAttribute("E")

				if (ParentElementNum == -1):
					print "ERROR: No parent element number was found. DPD Object ID: ", str(obj.GetObjectID())
				PDVList.append(obj.GetPDVCCode(ParentElementNum))
				DPD_ObjectID_C_Macros.append(obj.GetObjectID_C_Macro())
			else:
				nonDPD_ObjectID_C_Macros.append(obj.GetObjectID_C_Macro())

		self.CCode += "\n"
		self.CCode += "/*************************************************/\n/*\n"
		self.CCode += "   OBJECT POOL STRUCTURE:"		
		self.CCode += "\n*/\n/*************************************************/\n"
		
		self.CCode += "TC_ObjectPoolPart_T ObjectPoolParts[] =\n{\n"

		# Loop through every object name
		for objname in ObjectNames:
			self.CCode += "   "
			self.CCode += "{(void *)" + objname + ",sizeof(" + objname + ")},\n"
		self.CCode += "};\n"
		self.CCode += "\n"
		self.CCode += "/*************************************************/\n/*\n"
		self.CCode += "   PROCESS DATA VARIABLE LIST:\n"
		self.CCode += "\n"
		self.CCode += "     ObjectID\n"
		self.CCode += "     ElementNumber\n"
		self.CCode += "     DDI\n"
		self.CCode += "     Default\n"
		self.CCode += "     Triggermethod\n"
		self.CCode += "     SendInterval\n"
		self.CCode += "     DistanceInterval\n"
		self.CCode += "     LastSentAtDistance\n"
		self.CCode += "     SendTimer\n"
		self.CCode += "     MaxThreshold\n"
		self.CCode += "     MinThreshold\n"
		self.CCode += "     ChangeThreshold\n"
		self.CCode += "     ValueChangedFlag\n"
		self.CCode += "     Measurement\n"
		self.CCode += "     PDV_Value\n"
		self.CCode += "     *NextInList\n"		
		self.CCode += "\n*/\n/*************************************************/\n"		
		self.CCode += "TC_PDV_T pdvlist[] =\n{\n"

		# Loop through each PDV in the list (which is created in the object loop above)
		for pdvcode in PDVList:
			self.CCode += "   " + pdvcode + ",\n"
		self.CCode += "};\n\n"
		self.CCode += "/*************************************************/\n/*\n"
		self.CCode += "   DEVICE PROCESS DATA OBJECTS:"		
		self.CCode += "\n*/\n/*************************************************/\n"	
		for macro in DPD_ObjectID_C_Macros:
			if (macro != "DOR"):
				self.CCode += macro + "\n"
		self.CCode += "\n"
		self.CCode += "/*************************************************/\n/*\n"
		self.CCode += "   NON-DPD OBJECTS:"		
		self.CCode += "\n*/\n/*************************************************/\n"			
		for macro in nonDPD_ObjectID_C_Macros:
			if (macro != "DOR"):
				self.CCode += macro + "\n"
		self.CCode += "\n"
		self.CCode += "/*************************************************/\n/*\n"
		self.CCode += "   POOL INFORMATION:"
		self.CCode += "\n*/\n/*************************************************/\n"	
		self.CCode += "#define NUM_PDV " + str(len(PDVList))
		self.CCode += "\n#define NUM_POOL_OBJECTS " + str(len(self.DDObjects))
		self.CCode += "\n#define TOTAL_POOL_SIZE " + str(TotalPoolSize) + "\n"
		if (len(self.WSMNameOffset) >0 ):
			self.CCode += "#define WSMNAME_OFFSET_OBJECT_INDEX " + str(self.WSMNameOffset[0]) + "\n"
			self.CCode += "#define WSMNAME_OFFSET_BYTE_INDEX " + str(self.WSMNameOffset[1]) + "\n"
		if (len(self.StructureLabelOffset) > 0):
			self.CCode += "#define STRUCTURE_LABEL_OFFSET_OBJECT_INDEX " + str(self.StructureLabelOffset[0]) + "\n"
			self.CCode += "#define STRUCTURE_LABEL_OFFSET_BYTE_INDEX " + str(self.StructureLabelOffset[1]) + "\n"
			self.CCode += "#define STRUCTURE_LABEL " + PythonArrayToCArrayString(self.StructureLabel) + "\n"
		f = open('TestCode.c','w') # Open File for Writing
		f.write(self.CCode)	
		f.close()		
		print "Total Errors: ", ErrorCount
		if (ErrorCount > 0):
			for err in self.ErrorList:
				print "ERROR: " , err
			
 
OP = DDOP()

tree = ET.parse(xmlfile)
# taken from:
# http://www.xml.com/pub/a/2003/02/12/py-xml.html

# the tree root is the toplevel html element
print tree.findtext("head/title")

# if you need the root element, use getroot
root = tree.getroot()

#Create an iterator:
iter = root.getiterator()

# Loop through every element in the XML file:
for element in iter:
	# Switch on element name
	if   (element.tag == 'DVC'): # Device
		DVC = DDObject("DVC")
		# NullAttribute = ObjAttribute("",ObjAttributeType.NULL, 0, "")
		
		# Loop through attributes:
		for name, value in element.items():
			#print "\t\tName: '%s', Value: '%s'"%(name, value)
			if name == "A": # DeviceID
				DVC.A = ObjAttribute("DeviceID", ObjAttributeType.String, len(value), value)
			if name == "B": # DeviceDesignator
				DVC.B = ObjAttribute("DevieDesignator", ObjAttributeType.String, len(value), value)
			if name == "C": # DeviceSoftwareVersion
				DVC.C = ObjAttribute("DeviceSoftwareVersion", ObjAttributeType.String, len(value), value)
			if name == "D": # WorkingSetMasterNAME
				DVC.D = ObjAttribute("WorkingSetMasterNAME", ObjAttributeType.WSM_NAME, 8, value)
			if name == "E": # DeviceSerialNumber
				DVC.E = ObjAttribute("DeviceSerialNumber", ObjAttributeType.String, len(value), value)
			if name == "F": # DeviceStructureLabel
				DVC.F = ObjAttribute("DeviceStructureLabel", ObjAttributeType.ByteArray, 7, value)
			if name == "G": # DeviceLocalizationLabel
				DVC.G = ObjAttribute("DeviceLocalizationLabel", ObjAttributeType.ByteArray, 7, value)

		OP.AddObject(DVC)
	elif (element.tag == 'DET'): # DeviceElement
		DET = DDObject("DET") # Create new DET object
		# Loop through all attributes of the DET element:
		for name, value in element.items():
			#print "\t\tName: '%s', Value: '%s'"%(name, value)
			if name == "A": # DeviceElementId
				DET.A = ObjAttribute("DeviceElementId", ObjAttributeType.String, len(value), value)
			if name == "B": # DeviceElementObjectId
				DET.B = ObjAttribute("DeviceElementObjectId", ObjAttributeType.Base10Unsigned, 2, value)
			if name == "C": # DeviceElementType
				DET.C = ObjAttribute("DeviceElementType", ObjAttributeType.Base10Unsigned, 1, value)
			if name == "D": # DeviceElementDesignator
				DET.D = ObjAttribute("DeviceElementDesignator", ObjAttributeType.String, len(value), value)
			if name == "E": # DeviceElementNumber
				DET.E = ObjAttribute("DeviceElementNumber", ObjAttributeType.Base10Unsigned, 2, value)
			if name == "F": # ParentObjectId
				DET.F = ObjAttribute("ParentObjectId", ObjAttributeType.Base10Unsigned, 2, value)
		if element.getchildren():
				#Loop through child elements (Should be DOR)
				for child in element:
					if (child.tag == "DOR"):
						# loop through attributes of child element
						for name, value in child.items():				
							if name == "A":
								DET.AddRef(ObjAttribute("DeviceObjectId", ObjAttributeType.Base10Unsigned, 2, value))
		OP.AddObject(DET)
	elif (element.tag == 'DPD'): # DeviceProcessData
		DPD = DDObject("DPD")
		# Loop through attributes:
		for name, value in element.items():	
			if name == "A": # DeviceProcessDataObjectId
				DPD.A = ObjAttribute("DeviceProcessDataObjectId", ObjAttributeType.Base10Unsigned, 2, value)
			if name == "B": # DeviceProcessDataDDI
				DPD.B = ObjAttribute("DeviceProcessDataDDI", ObjAttributeType.Base16Unsigned, 2, value)
			if name == "C": # DeviceProcessDataProperty
				DPD.C = ObjAttribute("DeviceProcessDataProperty", ObjAttributeType.Base10Unsigned, 1, value)
			if name == "D": # DeviceProcessDataTriggerMethods
				DPD.D = ObjAttribute("DeviceProcessDataTriggerMethods", ObjAttributeType.Base10Unsigned, 1, value)
			if name == "E": # DeviceProcessDataDesignator
				DPD.E = ObjAttribute("DeviceProcessDataDesignator", ObjAttributeType.String, len(value), value)
			if name == "F": # DeviceValuePresentationObjectId
				DPD.F = ObjAttribute("DeviceValuePresentationObjectId", ObjAttributeType.Base10Unsigned, 2, value)
				
		OP.AddObject(DPD)
	elif (element.tag == 'DPT'): # DeviceProperty
		DPT = DDObject("DPT")
		# Loop through attributes:
		for name, value in element.items():		
			if name == "A": # DevicePropertyObjectId
				DPT.A = ObjAttribute("DevicePropertyObjectId", ObjAttributeType.Base10Unsigned, 2, value)
			if name == "B": # DevicePropertyDDI
				DPT.B = ObjAttribute("DevicePropertyDDI", ObjAttributeType.Base16Unsigned, 2, value)
			if name == "C": # DevicePropertyValue
				DPT.C = ObjAttribute("DevicePropertyValue", ObjAttributeType.Base10Signed, 4, value)
			if name == "D": # DevicePropertyDesignator
				DPT.D = ObjAttribute("DevicePropertyDesignator", ObjAttributeType.String, len(value), value)
			if name == "E": # DeviceValuePresentationObjectId
				DPT.E = ObjAttribute("DeviceValuePresentationObjectId", ObjAttributeType.Base10Unsigned, 2, value)
				
		OP.AddObject(DPT)
	elif (element.tag == 'DVP'): # DeviceValuePresentation
		DVP = DDObject("DVP")
		# Loop through attributes:
		for name, value in element.items():	
			if name == "A": # DeviceValuePresentationObjectId
				DVP.A = ObjAttribute("DeviceValuePresentationObjectId", ObjAttributeType.Base10Unsigned, 2, value)
			if name == "B": # Offset
				DVP.B = ObjAttribute("Offset", ObjAttributeType.Base10Signed, 4, value)
			if name == "C": # Scale
				DVP.C = ObjAttribute("Scale", ObjAttributeType.Base10Float, 4, value)
			if name == "D": # NumberOfDecimals
				DVP.D = ObjAttribute("NumberOfDecimals", ObjAttributeType.Base10Unsigned, 1, value)
			if name == "E": # UnitDesignator
				DVP.E = ObjAttribute("UnitDesignator", ObjAttributeType.String, len(value), value)
				
		OP.AddObject(DVP)

		
OP.GenerateCCode()


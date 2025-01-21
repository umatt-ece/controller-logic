/*
 * GNU GCC linker script for application signature block definition
 *
 * Ulrich Herb, STW                                22.02.2016
 *
 * The signature block must be allocated at a fixed address offset 0x200
 *
 */


SECTIONS
{
  /*
   *  This section provides a signature block that can be modified using the STWFlashSignatureGenerator
   *  tool in a post-build step. The linker will insert the start and end addresses of intern and
   *  external flash used by the application. The "QUAD(0);" entries are placeholder for the signature.
   *  This signature should be checked by the application to assure flash content integrity.
   *  Struct verion 4 is introduced for openSYDE, accordingly the variable name gt_OsyFlSignatureBlock is 
   *  needed by some openSYDE modules.
   *  The signature block must be allocated directly before the application info block.
   */
   .block_signature_v4 :
   {
      gt_OsyFlSignatureBlock = ABSOLUTE(.);
       
      /* magic key ";zwm2KgUZ!", zero terminated */
      LONG(0x6D777A3B);
      LONG(0x55674B32);
      SHORT(0x215A);
      BYTE(0x00);
      /* struct version */
      BYTE(0x04)
      /* struct size in byte */
      SHORT(0x0034);
      /* reserved */
      SHORT(0x0000);
      /* signature algorithm */
      SHORT(0x0002);
      /* number of next blocks */
      BYTE(0x00);
      /* number of memory areas to be checked */
      BYTE(0x02);
      /* memory area 1 start and end address (last used byte) */
      LONG(MEM_INT_ROM1_START);
      LONG(MEM_INT_ROM1_USED_END - MEM_INT_ROM1_START);
      /* memory area 2 start and end address (last used byte) */
      LONG(MEM_INT_ROM2_START);
      LONG(MEM_INT_ROM2_USED_END - MEM_INT_ROM2_START);
      /* signature for memory area 1 (filled in by signature tool) */
      QUAD(0);
      /* signature for memory area 2 (filled in by signature tool) */
      QUAD(0);
   } > MEM_APPLICATION_ROM
}

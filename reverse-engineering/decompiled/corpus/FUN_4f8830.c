/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f8830; label: FUN_004f8830
 */

float10 FUN_004f8830(void)

{
  float fVar1;
  int *unaff_ESI;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8790();
  while( true ) {
    while( true ) {
      fVar1 = (float)fVar2;
      if (*unaff_ESI != 2) break;
      FUN_004f8420();
      fVar2 = (float10)FUN_004f8790();
      fVar2 = fVar2 * (float10)fVar1;
    }
    if (*unaff_ESI != 3) break;
    FUN_004f8420();
    fVar2 = (float10)FUN_004f8790();
    fVar2 = (float10)fVar1 / fVar2;
  }
  return (float10)fVar1;
}


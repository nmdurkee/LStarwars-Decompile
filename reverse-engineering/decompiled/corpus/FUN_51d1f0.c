/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51d1f0; label: FUN_0051d1f0
 */

undefined4 FUN_0051d1f0(undefined4 param_1,uint *param_2,float *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  float10 fVar4;
  float local_8;
  
  iVar1 = *(int *)(unaff_EDI + 0x8c);
  local_8 = 3.4028235e+38;
  uVar2 = 0xffffffff;
  iVar3 = 0;
  if (*(char *)(unaff_EDI + 0x7a) != '\0') {
    do {
      fVar4 = (float10)FUN_005b3c50((uint)*(byte *)(iVar1 + iVar3 * 4) * 0x5c + 4 +
                                    *(int *)(unaff_EDI + 0x7c),param_1,0);
      if ((float)fVar4 < local_8) {
        uVar2 = (uint)*(byte *)(iVar1 + iVar3 * 4);
        local_8 = (float)fVar4;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(unaff_EDI + 0x7a));
    if (-1 < (int)uVar2) {
      *param_2 = uVar2;
      *param_3 = local_8;
      return 1;
    }
  }
  return 0;
}


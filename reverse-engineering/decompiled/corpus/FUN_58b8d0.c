/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b8d0; label: FUN_0058b8d0
 */

void FUN_0058b8d0(int param_1,undefined4 param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0x2adc) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar3 = FUN_004fc900("CharPlatforms",param_2,0xffff), iVar3 != 0)) {
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(undefined4 **)(param_1 + 0x2adc) = puVar4;
    *(undefined4 **)(param_1 + 0x104) = puVar4;
    *puVar4 = *(undefined4 *)(param_1 + 0x13c);
    *(undefined4 *)(*(int *)(param_1 + 0x2adc) + 4) = 0;
    iVar5 = FUN_004fc5b0(iVar3);
    while ((iVar5 != 0 && (iVar5 = FUN_004f7fb0(iVar3), iVar5 != 0))) {
      iVar5 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"char_platform");
      if ((iVar5 == 0) && (iVar5 = FUN_004f7fb0(iVar3), iVar5 != 0)) {
        iVar5 = *(int *)(param_1 + 0x2adc) + 8 + *(int *)(*(int *)(param_1 + 0x2adc) + 4) * 0x14;
        sVar2 = FUN_0055b1c0(*(undefined4 *)(iVar3 + 0x510));
        *(short *)(iVar5 + 0xc) = sVar2;
        if (((sVar2 != -1) && (iVar6 = FUN_004f7fb0(iVar3), iVar6 != 0)) &&
           (iVar6 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),iVar5,
                                 *(undefined4 *)(iVar3 + 0x510),1), iVar6 != 0)) {
          *(undefined2 *)(iVar5 + 0xe) = 0xffff;
          *(undefined4 *)(iVar5 + 0x10) = 0;
          piVar1 = (int *)(*(int *)(param_1 + 0x2adc) + 4);
          *piVar1 = *piVar1 + 1;
        }
      }
      iVar5 = FUN_004fc5b0(iVar3);
    }
    FUN_004fa300(iVar3);
    iVar3 = *(int *)(*(int *)(param_1 + 0x2adc) + 4);
    if (0 < iVar3) {
      *(uint *)(param_1 + 0x104) =
           *(int *)(param_1 + 0x104) + 0x1f + (iVar3 * 5 + -5) * 4 & 0xfffffffc;
      return;
    }
    *(undefined4 *)(param_1 + 0x2adc) = 0;
  }
  return;
}


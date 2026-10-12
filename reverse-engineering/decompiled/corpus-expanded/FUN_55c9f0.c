/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c9f0; label: FUN_0055c9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055c9f0(void)

{
  int iVar1;
  float10 extraout_ST0;
  undefined8 uVar2;
  
  iVar1 = FUN_0062a870(*(undefined4 *)(PTR_DAT_00802c54 + 0x298c));
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1fc) = *(uint *)(iVar1 + 0x1fc) | 0x1001;
    *(undefined4 *)(iVar1 + 0xa8) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0xff8) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x1014) = 0x49f42400;
    *(undefined1 *)(iVar1 + 0x671) = 0xff;
    *(undefined1 *)(iVar1 + 0x107a) = 2;
    uVar2 = __allshl();
    *(int *)(iVar1 + 0x1e8) = (int)uVar2;
    *(float *)(iVar1 + 0x224) = (float)extraout_ST0;
    *(int *)(iVar1 + 0x1ec) = (int)((ulonglong)uVar2 >> 0x20);
    *(float *)(iVar1 + 0x220) = (float)extraout_ST0;
    *(undefined4 *)(iVar1 + 0x1048) = 1;
    *(float *)(iVar1 + 0x21c) = (float)extraout_ST0;
    *(undefined1 *)(iVar1 + 0x284) = 0xff;
    *(undefined1 *)(iVar1 + 0x283) = 0xff;
    *(undefined1 *)(iVar1 + 0x285) = 0xff;
    FUN_0055c980();
    *(int *)iVar1 = iVar1;
    *(int *)(iVar1 + 0x398) = iVar1;
    *(int *)(iVar1 + 4) = iVar1 + 0x2c8;
    *(undefined4 *)(iVar1 + 0x2b0) = 0;
    *(undefined4 *)(iVar1 + 0x2b4) = 0;
    return iVar1;
  }
  return 0;
}


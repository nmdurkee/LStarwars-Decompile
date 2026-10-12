/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59bcc0; label: FUN_0059bcc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059bcc0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  short local_4 [2];
  
  iVar2 = FUN_0059bb30(param_1,local_4,0,0);
  uVar3 = 0;
  if (iVar2 != 0) {
    iVar2 = 0;
    if ((((*(int *)(param_1 + 0x798) != 0) && (DAT_00802850 != -1)) &&
        (*(char *)(param_1 + 0x7b5) == DAT_00802850)) &&
       ((uVar1 = *(uint *)(*(int *)(param_1 + 0x798) + 0x84), (uVar1 & 0x40) != 0 &&
        (iVar2 = DAT_008053c4, (uVar1 & 1) != 0)))) {
      iVar2 = -DAT_008053c4;
    }
    iVar2 = (iVar2 + 0xb4) * 0x10000;
    uVar3 = (undefined4)((longlong)iVar2 * -0x49f49f49);
    *(short *)(param_1 + 0x5a) =
         ((short)((ulonglong)((longlong)iVar2 * 0xb60b60b7) >> 0x28) -
         ((short)(char)((char)(iVar2 / 0x1680000) + (char)(iVar2 >> 0x1f)) >> 0xf)) + local_4[0];
  }
  return uVar3;
}


/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x4126b0; label: FUN_004126b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004126b0(int param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x511c);
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0x63734)) {
    pfVar3 = (float *)(iVar1 + 0x6373c);
    do {
      if ((pfVar3[-1] == *(float *)(*(int *)(param_1 + 0xd4) + 0x524)) &&
         (*(float *)(param_1 + 0xf8) == *pfVar3)) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      pfVar3 = pfVar3 + 4;
    } while (iVar2 < *(int *)(iVar1 + 0x63734));
    if (0xff < iVar2) {
      return 0;
    }
  }
  *(undefined4 *)(iVar2 * 0x10 + 0x63738 + iVar1) =
       *(undefined4 *)(*(int *)(param_1 + 0xd4) + 0x524);
  *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x511c) + 0x6373c + iVar2 * 0x10) =
       *(undefined4 *)(param_1 + 0xf8);
  *(int *)(*(int *)(PTR_DAT_00802c54 + 0x511c) + 0x63734) =
       *(int *)(*(int *)(PTR_DAT_00802c54 + 0x511c) + 0x63734) + 1;
  return 1;
}


/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621440; label: FUN_00621440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621440(void *param_1,size_t param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = DAT_02900a5c;
  while (0 < (int)param_2) {
    _Size = 0x1000U - iVar1;
    if ((int)param_2 < (int)(0x1000U - iVar1)) {
      _Size = param_2;
    }
    DAT_02900a5c = iVar1;
    _memcpy(&DAT_029110b8 + iVar1,param_1,_Size);
    DAT_02900a5c = iVar1 + _Size;
    param_2 = param_2 - _Size;
    param_1 = (void *)((int)param_1 + _Size);
    iVar1 = DAT_02900a5c;
    if ((((DAT_02900a5c == 0x1000) && (DAT_0080f884 != -1)) && (DAT_02912f3c != 0)) &&
       (DAT_02912f3c == 1)) {
      FUN_004f03d0(DAT_0080f884,&DAT_029110b8,0x1000);
      DAT_02900a5c = 0;
      iVar1 = DAT_02900a5c;
    }
  }
  DAT_02900a5c = iVar1;
  return;
}


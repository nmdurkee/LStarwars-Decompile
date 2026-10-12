/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652af0; label: FUN_00652af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00652af0(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (&DAT_008104a3)[-(int)DAT_00810494];
  if (cVar1 == '\0') {
    if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
      iVar2 = FUN_006984e0(1 - DAT_00810494);
      return iVar2 != 2;
    }
  }
  else {
    (&DAT_008104a3)[-(int)DAT_00810494] = cVar1 + -1;
  }
  return false;
}


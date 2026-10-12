/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7310; label: FUN_005d7310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7310(char *param_1)

{
  int iVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    param_1 = s_unknown_0080b9ec;
  }
  FUN_005d7230("<table width=100%c bgcolor=#DFDFE5><tr><td><font face=arial size=+2> ",0x25);
  _vsprintf(DAT_0096e574,param_1,&stack0x00000008);
  iVar1 = FUN_004f1ff0(DAT_0096e574);
  DAT_0096e574 = DAT_0096e574 + iVar1;
  FUN_005d7230("</font></table>\n");
  return;
}


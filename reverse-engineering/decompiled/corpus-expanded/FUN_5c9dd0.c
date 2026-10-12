/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9dd0; label: FUN_005c9dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005c9dd0(int param_1)

{
  int *piVar1;
  void *_Dst;
  
  piVar1 = (int *)FUN_004eef40(0x14,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4a8);
  piVar1[1] = 0;
  piVar1[2] = 0;
  piVar1[3] = 0;
  piVar1[4] = 0;
  *piVar1 = param_1;
  _Dst = (void *)FUN_004eef40(param_1 * 4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",
                              0x4ac);
  piVar1[2] = (int)_Dst;
  _memset(_Dst,0,param_1 * 4);
  return piVar1;
}


/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x607a90; label: FUN_00607a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00607a90(undefined4 param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  
  _DAT_02854c44 = 1;
  _DAT_02854c48 = 1;
  FUN_005b44e0(&DAT_02854b48);
  FUN_00605e60(param_1,param_2);
  DAT_02854bf4 = 0;
  _DAT_00973fe0 = 0x40800000;
  DAT_02854bf8 = 0xbf400000;
  DAT_02854bfc = 0xbf400000;
  _DAT_00973fe4 = 0x40c00000;
  DAT_02854c00 = 0x101010;
  DAT_02854c84 = 0;
  puVar1 = &DAT_00981cc0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x14;
  } while ((int)puVar1 < 0x9821c0);
  FUN_005ec6b0();
  return;
}


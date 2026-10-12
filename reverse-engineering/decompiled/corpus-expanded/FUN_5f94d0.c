/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f94d0; label: FUN_005f94d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f94d0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_004eef40(0x24,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x1e1);
  iVar2 = FUN_005f9130(param_1,0,uVar1);
  if (iVar2 == 0) {
    FUN_004ef280(uVar1,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x1e5);
    return 0;
  }
  return uVar1;
}


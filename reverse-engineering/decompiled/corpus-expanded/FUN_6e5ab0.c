/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e5ab0; label: FUN_006e5ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5ab0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004fa690(param_1);
  if (iVar1 != 0) {
    iVar2 = FUN_004fd550(param_1);
    if (iVar2 != 0) {
      _DAT_0297bea0 = D3DXCreateCubeTextureFromFileInMemory(DAT_029765cc,iVar2,iVar1,param_2);
      FUN_004ef280(iVar2,".\\d3dCalls.cpp",0x45c);
    }
  }
  return;
}


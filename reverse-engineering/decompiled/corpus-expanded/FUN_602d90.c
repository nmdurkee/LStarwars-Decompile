/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602d90; label: FUN_00602d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00602d90(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *_Dst;
  int iVar2;
  undefined4 *puVar3;
  
  _Dst = (undefined4 *)
         FUN_004eef40(0x98,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x170);
  _memset(_Dst,0,0x98);
  uVar1 = *_Dst;
  puVar3 = _Dst;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  *_Dst = uVar1;
  FUN_005f7490();
  return _Dst;
}


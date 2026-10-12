/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fd550; label: FUN_004fd550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004fd550(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_0091ee90;
  iVar4 = 0;
  DAT_0091ee90 = 0;
  iVar2 = FUN_004fa3f0(param_1,0,DAT_0091ee88,0);
  if (iVar2 != 0) {
    iVar3 = FUN_004f6b40(iVar2);
    if (0 < iVar3) {
      iVar4 = FUN_004eef40(iVar3,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nufile.c",0x64b);
      if (iVar4 != 0) {
        FUN_004fb550(iVar2,iVar4,iVar3);
      }
    }
    FUN_004f99e0(iVar2);
  }
  DAT_0091ee90 = uVar1;
  return iVar4;
}


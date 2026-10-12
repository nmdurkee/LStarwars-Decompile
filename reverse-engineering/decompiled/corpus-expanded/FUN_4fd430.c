/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fd430; label: FUN_004fd430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fd430(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  DAT_0297dc08 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_004fa3f0(param_1,0,DAT_0091ee88,0), iVar2 != 0)) {
    FUN_004fb550(iVar2,&param_1,4);
    iVar1 = param_1;
    iVar3 = FUN_004eef40(param_1 + 4,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nupad.cpp",1099
                        );
    DAT_0297dc14 = iVar3 + 3U & 0xfffffffc;
    if (DAT_0297dc14 == 0) {
      FUN_004ef790();
      return;
    }
    DAT_0297dc0c = DAT_0297dc14;
    FUN_004fb550(iVar2,DAT_0297dc14,iVar1);
    FUN_004f99e0(iVar2);
    DAT_0297dc10 = DAT_0297dc14 + iVar1;
    DAT_0297dc08 = 2;
  }
  return;
}


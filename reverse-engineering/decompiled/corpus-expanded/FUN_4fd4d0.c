/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fd4d0; label: FUN_004fd4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fd4d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  if (param_1 == 1) {
    DAT_0297dc08 = 1;
    iVar1 = FUN_004eef40(param_5 + 4,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nupad.cpp",
                         0x47a);
    DAT_0297dc14 = iVar1 + 3U & 0xfffffffc;
    DAT_0297dc0c = DAT_0297dc14;
    DAT_0297dc10 = DAT_0297dc14 + param_5;
    DAT_0297dc1c = param_2;
    return;
  }
  if (param_1 != 2) {
    DAT_0297dc08 = 0;
    return;
  }
  FUN_004fd430(param_2,param_3,param_4);
  DAT_0297dc1c = param_2;
  return;
}


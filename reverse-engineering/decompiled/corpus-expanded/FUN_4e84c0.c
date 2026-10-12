/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e84c0; label: FUN_004e84c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e84c0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005aac00(DAT_0095df4c,"CompletedTraining",0);
  if (((DAT_0093b2a4 == 0) && (iVar1 != 0)) && (*(float *)(iVar1 + 0x28) == 0.0)) {
    DAT_0088a54c = 1;
    iVar2 = FUN_005756c0(param_1,"door_e_to_b");
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0xf5) = *(byte *)(iVar2 + 0xf5) | 4;
    }
    iVar2 = FUN_005756c0(param_1,"door_b_to_e");
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0xf5) = *(byte *)(iVar2 + 0xf5) | 4;
    }
  }
  else {
    DAT_0088a54c = 0;
    iVar2 = FUN_005756c0(param_1,"door_e_to_b");
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0xf5) = *(byte *)(iVar2 + 0xf5) & 0xfb;
    }
    iVar2 = FUN_005756c0(param_1,"door_b_to_e");
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0xf5) = *(byte *)(iVar2 + 0xf5) & 0xfb;
    }
  }
  FUN_005ab050(DAT_0095df4c,"DagobahTraining",(float)DAT_0088a54c,0);
  FUN_005ab050(DAT_0095df4c,0,0x3f800000,iVar1);
  return;
}


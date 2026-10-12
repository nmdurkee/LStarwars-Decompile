/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a16b0; label: FUN_005a16b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a16b0(int param_1,int param_2,float param_3,int param_4)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_40 [64];
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    if (param_4 == 0) {
      param_4 = FUN_005cfa20(*(int *)(param_1 + 0x18) + 4);
    }
    fVar2 = *(float *)(param_4 + 0x2c + param_2 * 4);
    FUN_005d4690(0);
    for (puVar3 = *(undefined4 **)(param_1 + 0x18); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      if ((*(byte *)(puVar3 + 8) & 2) == 0) {
        puVar1 = puVar3 + 1;
        iVar4 = FUN_005cfd60(puVar1);
        if (iVar4 != 0) {
          uVar5 = FUN_005d0330(puVar1);
          iVar4 = FUN_00550490(uVar5,param_2,fVar2 + param_3,
                               *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),auStack_40
                              );
          if (iVar4 != 0) {
            FUN_005f33b0(puVar1,auStack_40);
          }
        }
      }
    }
    FUN_005d46b0();
  }
  return;
}


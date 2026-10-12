/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58bee0; label: FUN_0058bee0
 */

void FUN_0058bee0(int param_1,int param_2,char param_3,float param_4,float param_5,float param_6)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  
  if (param_2 != 0) {
    if ((*(int *)(param_1 + 0xfd8) == 0) ||
       ((param_2 != *(int *)(param_1 + 0xfd8) && (*(char *)(param_1 + 0x1080) <= param_3)))) {
      iVar3 = FUN_0054fa60();
      *(int *)(param_1 + 0xfd8) = param_2;
      *(char *)(param_1 + 0x1080) = param_3;
      fVar2 = (1.0 - (float)iVar3 * 1.5259022e-05) * param_5 +
              param_6 * (float)iVar3 * 1.5259022e-05;
      *(float *)(param_1 + 0xfe8) = fVar2 + param_4;
      *(float *)(param_1 + 0xfec) = fVar2;
    }
    puVar1 = *(undefined4 **)(param_1 + 0xfd8);
    *(undefined4 *)(param_1 + 0xfdc) = *puVar1;
    *(undefined4 *)(param_1 + 0xfe0) = puVar1[1];
    *(undefined4 *)(param_1 + 0xfe4) = puVar1[2];
    return;
  }
  *(undefined4 *)(param_1 + 0xfe8) = 0;
  *(undefined4 *)(param_1 + 0xfd8) = 0;
  *(undefined4 *)(param_1 + 0xfec) = 0;
  *(undefined1 *)(param_1 + 0x1080) = 0;
  return;
}


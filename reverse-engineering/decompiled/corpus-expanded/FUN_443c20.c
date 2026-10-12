/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443c20; label: FUN_00443c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443c20(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((((param_5 != 0) && (*(int *)(param_2 + 0xa4) != 0)) && (param_3 != 0)) &&
      ((*(int *)(param_3 + 0xd0) != 0 &&
       ((iVar3 = DAT_0093d810, param_5 == -1 || (iVar3 = DAT_0093d7f4, param_5 == 1)))))) &&
     (iVar3 != 0)) {
    uVar1 = FUN_005be2d0(*(float *)(*(int *)(param_3 + 0xd0) + 0x5c) -
                         *(float *)(*(int *)(param_2 + 0xa4) + 0x10),
                         *(float *)(*(int *)(param_3 + 0xd0) + 100) -
                         *(float *)(*(int *)(param_2 + 0xa4) + 0x18));
    uVar2 = FUN_005be2d0(*(float *)(iVar3 + 0x5c) - *(float *)(*(int *)(param_2 + 0xa4) + 0x10),
                         *(float *)(iVar3 + 100) - *(float *)(*(int *)(param_2 + 0xa4) + 0x18));
    iVar3 = FUN_005be5b0(uVar2,uVar1);
    return (float10)iVar3;
  }
  return (float10)0;
}


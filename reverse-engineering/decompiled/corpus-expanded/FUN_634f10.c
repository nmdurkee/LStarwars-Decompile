/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x634f10; label: FUN_00634f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00634f10(int param_1,undefined4 param_2,float *param_3)

{
  int in_ECX;
  
  FUN_006c5f80(param_2);
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0x80000002:
    _sprintf((char *)param_3,"Fog%d",((param_1 - DAT_0291389c) + -0x4604) / 0x4c);
    return;
  case 0x80000003:
    *param_3 = (float)*(byte *)(param_1 + 8) * 0.003921569;
    param_3[1] = (float)*(byte *)(param_1 + 9) * 0.003921569;
    param_3[2] = (float)*(byte *)(param_1 + 10) * 0.003921569;
    return;
  case 0x80000004:
    *param_3 = (float)*(byte *)(param_1 + 0xb) * 0.0078125;
    return;
  case 0x80000005:
    *param_3 = (float)*(byte *)(param_1 + 0x10) * 0.003921569;
    param_3[1] = (float)*(byte *)(param_1 + 0x11) * 0.003921569;
    param_3[2] = (float)*(byte *)(param_1 + 0x12) * 0.003921569;
    return;
  case 0x80000006:
    *param_3 = (float)*(byte *)(param_1 + 0x13) * 0.0078125;
    return;
  case 0x80000007:
    *param_3 = (float)*(int *)(param_1 + 0xc) * 0.0078125;
    return;
  case 0x80000008:
    *param_3 = (float)*(byte *)(param_1 + 0x18) * 0.1;
    return;
  case 0x80000009:
    *param_3 = *(float *)(param_1 + 0x20);
    param_3[1] = *(float *)(param_1 + 0x24);
    param_3[2] = *(float *)(param_1 + 0x28);
  }
  return;
}


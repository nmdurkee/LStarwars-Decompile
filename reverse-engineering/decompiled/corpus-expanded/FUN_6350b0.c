/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x6350b0; label: FUN_006350b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006350b0(int param_1,undefined4 param_2,float *param_3)

{
  undefined4 uVar1;
  int in_ECX;
  int local_8;
  
  FUN_006c5f80(param_2);
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0x80000003:
    local_8._0_1_ = (undefined1)(longlong)ROUND(*param_3 * 255.0);
    *(uint *)(param_1 + 8) =
         (uint)CONCAT21(CONCAT11((char)(longlong)ROUND(param_3[2] * 255.0),
                                 (char)(longlong)ROUND(param_3[1] * 255.0)),(undefined1)local_8) |
         *(uint *)(param_1 + 8) & 0xff000000;
    return;
  case 0x80000004:
    *(undefined1 *)(param_1 + 0xb) = 0;
    local_8 = (int)(longlong)ROUND(*param_3 * 128.0);
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | local_8 << 0x18;
    return;
  case 0x80000005:
    local_8._0_1_ = (undefined1)(longlong)ROUND(*param_3 * 255.0);
    *(uint *)(param_1 + 0x10) =
         (uint)CONCAT21(CONCAT11((char)(longlong)ROUND(param_3[2] * 255.0),
                                 (char)(longlong)ROUND(param_3[1] * 255.0)),(undefined1)local_8) |
         *(uint *)(param_1 + 0x10) & 0xff000000;
    return;
  case 0x80000006:
    *(undefined1 *)(param_1 + 0x13) = 0;
    local_8 = (int)(longlong)ROUND(*param_3 * 128.0);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | local_8 << 0x18;
    return;
  case 0x80000007:
    uVar1 = FUN_006e6b90();
    *(undefined4 *)(param_1 + 0xc) = uVar1;
    return;
  case 0x80000008:
    param_2._0_1_ = (undefined1)(int)ROUND(*param_3 * 10.0);
    *(undefined1 *)(param_1 + 0x18) = (undefined1)param_2;
    return;
  case 0x80000009:
    *(float *)(param_1 + 0x20) = *param_3;
    *(float *)(param_1 + 0x24) = param_3[1];
    *(float *)(param_1 + 0x28) = param_3[2];
  }
  return;
}


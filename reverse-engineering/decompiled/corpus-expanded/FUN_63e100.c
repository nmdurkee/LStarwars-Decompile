/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63e100; label: FUN_0063e100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063e100(undefined4 *param_1,undefined4 param_2,uint *param_3)

{
  int in_ECX;
  int extraout_ECX;
  
  FUN_006c5f80(param_2);
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0x80000002:
    _sprintf((char *)param_3,"Light%d",((int)param_1 + (-4 - DAT_0291389c)) / 0x8c);
    return;
  case 0x80000003:
    FUN_006340e0();
    *(undefined4 *)(extraout_ECX + 0x30) = *param_1;
    *(undefined4 *)(extraout_ECX + 0x34) = param_1[1];
    *(undefined4 *)(extraout_ECX + 0x38) = param_1[2];
    FUN_005b65a0(extraout_ECX,param_1 + 3);
    return;
  case 0x80000004:
    *param_3 = (uint)*(byte *)(param_1 + 0x16);
    return;
  case 0x80000005:
    *param_3 = *(byte *)((int)param_1 + 0x59) & 1;
    return;
  case 0x80000006:
    *param_3 = *(byte *)((int)param_1 + 0x59) >> 1 & 1;
    return;
  case 0x80000007:
    *param_3 = *(byte *)((int)param_1 + 0x59) >> 2 & 1;
    return;
  case 0x80000008:
    *param_3 = param_1[0xf];
    return;
  case 0x80000009:
    *param_3 = param_1[0x10];
    return;
  case 0x8000000a:
    *param_3 = (uint)*(ushort *)((int)param_1 + 0x5e);
    return;
  case 0x8000000b:
    *param_3 = (uint)*(ushort *)(param_1 + 0x18);
    return;
  case 0x8000000c:
    *param_3 = (uint)*(ushort *)(param_1 + 0x1a);
    return;
  case 0x8000000d:
    *param_3 = (uint)*(byte *)(param_1 + 0x1e);
    return;
  case 0x8000000e:
    *param_3 = (int)*(char *)((int)param_1 + 0x7b);
  }
  return;
}


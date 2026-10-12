/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x634670; label: FUN_00634670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00634670(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  ushort uVar2;
  int in_ECX;
  
  FUN_006c5f80(param_2);
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0x80000003:
    *param_1 = param_3[0xc];
    param_1[1] = param_3[0xd];
    param_1[2] = param_3[0xe];
    param_1[3] = param_3[8];
    param_1[4] = param_3[9];
    param_1[5] = param_3[10];
    return;
  case 0x80000004:
    *(undefined1 *)(param_1 + 0x16) = *(undefined1 *)param_3;
    return;
  case 0x80000005:
    *(byte *)((int)param_1 + 0x59) =
         *(byte *)((int)param_1 + 0x59) ^ (*(byte *)((int)param_1 + 0x59) ^ *(byte *)param_3) & 1;
    return;
  case 0x80000006:
    *(byte *)((int)param_1 + 0x59) =
         *(byte *)((int)param_1 + 0x59) ^
         (*(char *)param_3 * '\x02' ^ *(byte *)((int)param_1 + 0x59)) & 2;
    return;
  case 0x80000007:
    *(byte *)((int)param_1 + 0x59) =
         *(byte *)((int)param_1 + 0x59) ^
         (*(char *)param_3 * '\x04' ^ *(byte *)((int)param_1 + 0x59)) & 4;
    return;
  case 0x80000008:
    if (*param_3 < 0.1) {
      *param_3 = 0.1;
    }
    fVar1 = *param_3;
    param_1[0xf] = fVar1;
    if (param_1[0x10] < fVar1) {
      param_1[0x10] = fVar1;
      return;
    }
    break;
  case 0x80000009:
    if (*param_3 < 0.1) {
      *param_3 = 0.1;
    }
    fVar1 = *param_3;
    param_1[0x10] = fVar1;
    if (fVar1 < param_1[0xf]) {
      param_1[0xf] = fVar1;
      return;
    }
    break;
  case 0x8000000a:
    uVar2 = *(ushort *)param_3;
    *(ushort *)((int)param_1 + 0x5e) = uVar2;
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & ~uVar2;
    return;
  case 0x8000000b:
    uVar2 = *(ushort *)param_3;
    *(ushort *)(param_1 + 0x18) = uVar2;
    *(ushort *)((int)param_1 + 0x5e) = *(ushort *)((int)param_1 + 0x5e) & ~uVar2;
    return;
  case 0x8000000c:
    *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)param_3;
    return;
  case 0x8000000d:
    *(undefined1 *)(param_1 + 0x1e) = *(undefined1 *)param_3;
    return;
  case 0x8000000e:
    *(undefined1 *)((int)param_1 + 0x7b) = *(undefined1 *)param_3;
    return;
  }
  return;
}


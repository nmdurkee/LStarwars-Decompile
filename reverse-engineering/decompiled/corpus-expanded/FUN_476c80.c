/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476c80; label: FUN_00476c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00476c80(int param_1,int param_2)

{
  int *in_EAX;
  uint uVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = (uint)*(ushort *)((int)in_EAX + 6);
  uVar2 = (uint)*(ushort *)(in_EAX + 1);
  uVar5 = in_ECX - 1U & 1;
  iVar4 = (int)((ulonglong)uVar1 / (ulonglong)(longlong)(int)uVar2) + 1;
  if (param_1 == 0) {
    do {
      param_2 = param_2 - uVar2;
      if ((param_2 < 0) && (param_2 = param_2 + iVar4 * uVar2, (int)uVar1 <= param_2)) {
        param_2 = param_2 - uVar2;
      }
    } while (*(short *)(*in_EAX + param_2 * 0x1c) == (&DAT_0087b6c4)[uVar5]);
    return;
  }
  if (param_1 == 1) {
    do {
      param_2 = param_2 + uVar2;
      if ((int)uVar1 <= param_2) {
        iVar3 = iVar4 * uVar2;
        if (param_2 < iVar3) {
          param_2 = param_2 + uVar2;
        }
        param_2 = param_2 - iVar3;
      }
    } while (*(short *)(*in_EAX + param_2 * 0x1c) == (&DAT_0087b6c4)[uVar5]);
    return;
  }
  if (param_1 == 2) {
    do {
      iVar4 = param_2 % (int)uVar2 + -1;
      if (iVar4 < 0) {
        iVar4 = iVar4 + uVar2;
      }
      param_2 = (param_2 / (int)uVar2) * uVar2 + iVar4;
      if ((int)uVar1 <= param_2) {
        param_2 = uVar1 - 1;
      }
    } while (*(short *)(*in_EAX + param_2 * 0x1c) == (&DAT_0087b6c4)[uVar5]);
    return;
  }
  if (param_1 == 3) {
    do {
      iVar4 = param_2 % (int)uVar2 + 1;
      if ((int)uVar2 <= iVar4) {
        iVar4 = iVar4 - uVar2;
      }
      iVar3 = (param_2 / (int)uVar2) * uVar2;
      param_2 = iVar3 + iVar4;
      if ((int)uVar1 <= param_2) {
        param_2 = iVar3;
      }
    } while (*(short *)(*in_EAX + param_2 * 0x1c) == (&DAT_0087b6c4)[uVar5]);
  }
  return;
}


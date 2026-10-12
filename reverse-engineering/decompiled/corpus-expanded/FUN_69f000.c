/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69f000; label: FUN_0069f000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069f000(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  size_t _NewSize;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = (int)param_2[1] / 0xff;
  iVar3 = iVar6 + 1;
  iVar9 = param_1[3];
  if (iVar9 != 0) {
    piVar1 = param_1 + 2;
    *piVar1 = *piVar1 - iVar9;
    if (*piVar1 != 0) {
      _memmove((void *)*param_1,(void *)(*param_1 + iVar9),param_1[2]);
    }
    param_1[3] = 0;
  }
  if (param_1[1] <= param_1[2] + param_2[1]) {
    _NewSize = param_1[1] + 0x400 + param_2[1];
    param_1[1] = _NewSize;
    pvVar7 = _realloc((void *)*param_1,_NewSize);
    *param_1 = (int)pvVar7;
  }
  if (param_1[6] <= param_1[7] + iVar3) {
    iVar9 = param_1[6] + 0x20 + iVar3;
    param_1[6] = iVar9;
    pvVar7 = _realloc((void *)param_1[4],iVar9 * 4);
    param_1[4] = (int)pvVar7;
    pvVar7 = _realloc((void *)param_1[5],param_1[6] * 8);
    param_1[5] = (int)pvVar7;
  }
  _memcpy((void *)(param_1[2] + *param_1),(void *)*param_2,param_2[1]);
  param_1[2] = param_1[2] + param_2[1];
  iVar9 = 0;
  if (0 < iVar6) {
    do {
      *(undefined4 *)(param_1[4] + (param_1[7] + iVar9) * 4) = 0xff;
      iVar5 = param_1[5];
      iVar8 = param_1[7] + iVar9;
      *(int *)(iVar5 + iVar8 * 8) = param_1[0x58];
      iVar9 = iVar9 + 1;
      *(int *)(iVar5 + 4 + iVar8 * 8) = param_1[0x59];
    } while (iVar9 < iVar6);
  }
  *(int *)(param_1[4] + (param_1[7] + iVar9) * 4) = (int)param_2[1] % 0xff;
  iVar6 = param_1[7];
  iVar5 = param_1[5];
  *(undefined4 *)(iVar5 + (iVar6 + iVar9) * 8) = param_2[4];
  *(undefined4 *)(iVar5 + 4 + (iVar6 + iVar9) * 8) = param_2[5];
  iVar9 = param_1[7] + iVar9;
  param_1[0x58] = *(int *)(param_1[5] + iVar9 * 8);
  puVar2 = (uint *)(param_1[4] + param_1[7] * 4);
  param_1[0x59] = *(int *)(param_1[5] + 4 + iVar9 * 8);
  *puVar2 = *puVar2 | 0x100;
  param_1[7] = param_1[7] + iVar3;
  puVar2 = (uint *)(param_1 + 0x56);
  uVar4 = *puVar2;
  *puVar2 = *puVar2 + 1;
  param_1[0x57] = param_1[0x57] + (uint)(0xfffffffe < uVar4);
  if (param_2[3] != 0) {
    param_1[0x52] = 1;
  }
  return 0;
}


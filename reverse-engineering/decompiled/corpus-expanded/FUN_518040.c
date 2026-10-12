/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x518040; label: FUN_00518040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00518040(int *param_1,int param_2)

{
  uint uVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  undefined1 local_4;
  
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (*(byte *)((int)param_1 + 7) < 0x10)) {
    uVar5 = (uint)*(byte *)(param_1 + 2);
    uVar1 = *(byte *)((int)param_1 + 7) + 1;
    FUN_005128a0((float)uVar1,(float)uVar5);
    iVar4 = FUN_006e6b90();
    if ((int)((ulonglong)uVar1 % (ulonglong)(longlong)(int)uVar5) != 0) {
      iVar4 = iVar4 + 1;
    }
    if (iVar4 < 5) {
      if (*(char *)((int)param_1 + 7) == '\0') {
        *param_1 = param_2;
        if ((float)param_1[0x4a] <= 0.0) {
          param_1[0x49] = 0;
          *(undefined2 *)(param_1 + 1) = 100;
        }
        else {
          fVar2 = ((float)uVar5 - 1.0) * (float)param_1[0x4a] * 0.5;
          param_1[0x49] = (int)fVar2;
          FUN_005128a0(param_1[0x4c],fVar2 * 60.0);
          uVar3 = FUN_006e6b90();
          *(undefined2 *)(param_1 + 1) = uVar3;
        }
      }
      *(char *)((int)param_1 + 6) = (char)iVar4;
      *(int **)(*(int *)(param_2 + 4) + 0x144) = param_1;
      *(undefined1 *)(*(int *)(param_2 + 4) + 0x148) = *(undefined1 *)((int)param_1 + 7);
      fVar6 = (float10)FUN_005128a0((float)*(byte *)((int)param_1 + 7),(float)*(byte *)(param_1 + 2)
                                   );
      local_4 = (undefined1)(int)ROUND(fVar6);
      *(undefined1 *)(*(int *)(param_2 + 4) + 0x14a) = local_4;
      *(char *)(*(int *)(param_2 + 4) + 0x149) =
           (char)((ulonglong)*(byte *)((int)param_1 + 7) %
                 (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 2));
      param_1[*(byte *)((int)param_1 + 7) + 3] = param_2;
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    }
  }
  return;
}


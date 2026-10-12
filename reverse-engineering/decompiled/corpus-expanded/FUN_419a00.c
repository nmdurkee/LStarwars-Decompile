/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x419a00; label: FUN_00419a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00419a00(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float local_98;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar7 = param_2 * 0x10;
  if ((((*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar7) != '\0') && (in_EAX != -1)) &&
      (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + in_EAX * 4) != 0)) &&
     (pfVar4 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
     pfVar4 != (float *)0x0)) {
    fVar10 = (float10)FUN_005ca470(*(undefined4 *)
                                    (*(int *)(*(int *)(param_1 + 0x50) + 0xc) +
                                    *(short *)(param_1 + 0x7aa) * 4));
    fVar1 = (float)fVar10;
    fVar10 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),
                                   0);
    local_98 = (float)fVar10;
    if (fVar1 < local_98 == (fVar1 == local_98)) {
      if (local_98 < 1.0) {
        local_98 = 1.0;
      }
      if (local_98 <= *pfVar4) {
        fVar10 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                       (int)*(short *)(param_1 + 0x7aa),1);
        fVar2 = (float)fVar10;
        if (local_98 < fVar2) {
          fVar10 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                         (int)*(short *)(param_1 + 0x7aa),2);
          fVar3 = (float)fVar10;
          if ((float)fVar10 < fVar2) {
            fVar3 = fVar2;
          }
          if (fVar1 < fVar2) {
            fVar2 = fVar1;
          }
          if (fVar1 < fVar3) {
            fVar3 = fVar1;
          }
          if (*pfVar4 < fVar2 == (*pfVar4 == fVar2)) {
            if (fVar3 <= *pfVar4) {
              return;
            }
            if (fVar3 <= fVar2) {
              return;
            }
            local_8c = 1.0 - (*pfVar4 - fVar2) / (fVar3 - fVar2);
          }
          else {
            local_8c = 1.0;
          }
          puVar8 = (undefined4 *)(in_EAX * 0x40 + 0x804 + param_1);
          puVar9 = local_80;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          local_88 = local_8c;
          local_84 = local_8c;
          if (param_2 == 0xec) {
            iVar6 = 0xed;
            FUN_005b5060(local_80,*(undefined2 *)(param_1 + 0x7a6));
          }
          else {
            iVar6 = -1;
          }
          FUN_005b4c30(local_80,&local_8c);
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar7,local_80);
          if ((iVar6 != -1) &&
             (iVar5 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar6 * 0x10,
             *(char *)(iVar5 + 0xe) != '\0')) {
            FUN_005f33b0(iVar5,local_80);
          }
          if (((param_3 != 0) &&
              (iVar5 = FUN_00550490(local_80,*(undefined1 *)(param_1 + 0x107b),
                                    *(undefined4 *)(param_1 + 0x1014),
                                    *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                    local_40), iVar5 != 0)) &&
             ((FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar7,local_40), iVar6 != -1 &&
              (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar6 * 0x10) != '\0')))) {
            FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar6 * 0x10,local_80);
            return;
          }
        }
      }
    }
  }
  return;
}


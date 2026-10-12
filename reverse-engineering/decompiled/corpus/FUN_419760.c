/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x419760; label: FUN_00419760
 */

void FUN_00419760(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_98;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar6 = param_2 * 0x10;
  if ((((*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar6) != '\0') && (in_EAX != -1)) &&
      (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + in_EAX * 4) != 0)) &&
     (pfVar3 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
     pfVar3 != (float *)0x0)) {
    fVar9 = (float10)FUN_005ca470(*(undefined4 *)
                                   (*(int *)(*(int *)(param_1 + 0x50) + 0xc) +
                                   *(short *)(param_1 + 0x7aa) * 4));
    fVar1 = (float)fVar9;
    fVar9 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),0
                                 );
    local_98 = (float)fVar9;
    if (fVar1 < local_98 == (fVar1 == local_98)) {
      if (local_98 < 1.0) {
        local_98 = 1.0;
      }
      if (local_98 <= *pfVar3) {
        fVar9 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                      (int)*(short *)(param_1 + 0x7aa),1);
        fVar2 = (float)fVar9;
        if (local_98 < fVar2) {
          if (fVar1 < fVar2) {
            fVar2 = fVar1;
          }
          if (fVar2 <= *pfVar3) {
            local_8c = 1.0;
          }
          else {
            local_8c = (*pfVar3 - local_98) / (fVar2 - local_98);
          }
          puVar7 = (undefined4 *)(in_EAX * 0x40 + 0x804 + param_1);
          puVar8 = local_80;
          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          local_88 = local_8c;
          local_84 = local_8c;
          if (param_2 == 0xec) {
            iVar5 = 0xed;
            FUN_005b5060(local_80,*(undefined2 *)(param_1 + 0x7a6));
          }
          else {
            iVar5 = -1;
          }
          FUN_005b4c30(local_80,&local_8c);
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar6,local_80);
          if ((iVar5 != -1) &&
             (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar5 * 0x10) != '\0')) {
            FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar5 * 0x10,local_80);
          }
          if (((param_3 != 0) &&
              (iVar4 = FUN_00550490(local_80,*(undefined1 *)(param_1 + 0x107b),
                                    *(undefined4 *)(param_1 + 0x1014),
                                    *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                    local_40), iVar4 != 0)) &&
             ((FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar6,local_40), iVar5 != -1 &&
              (iVar6 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar5 * 0x10,
              *(char *)(iVar6 + 0xe) != '\0')))) {
            FUN_005f33b0(iVar6,local_80);
            return;
          }
        }
      }
    }
  }
  return;
}


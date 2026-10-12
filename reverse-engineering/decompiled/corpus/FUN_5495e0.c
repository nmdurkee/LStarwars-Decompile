/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x5495e0; label: FUN_005495e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005495e0(undefined *param_1)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined *puVar7;
  float10 fVar8;
  float local_c;
  int iStack_4;
  
  puVar7 = param_1;
  if (param_1 == (undefined *)0x0) {
    puVar7 = PTR_DAT_008021b4;
  }
  *(undefined4 *)(puVar7 + 0x204) = 0;
  *(undefined4 *)(puVar7 + 0x208) = 0;
  if (DAT_00855de0 == 0) {
    local_c = 0.0;
    piVar6 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar6;
      if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
         (**(int **)(iVar1 + 0xca4) != 0)) {
        if (DAT_00925160 == (code *)0x0) {
LAB_00549784:
          iVar1 = DAT_008021c4;
          param_1 = (undefined *)
                    (((float)*(byte *)(**(int **)(*piVar6 + 0xca4) + 0x90) - 127.5) * 0.007843138);
          *(float *)(puVar7 + 0x204) =
               ((float)*(byte *)(**(int **)(*piVar6 + 0xca4) + 0x91) - 127.5) * 0.007843138 *
               (float)((DAT_008021c0 * 0x10000) / 0x168) + *(float *)(puVar7 + 0x204);
        }
        else {
          iVar4 = (*DAT_00925160)(iVar1);
          iVar1 = DAT_008021c4;
          if (iVar4 != 2) {
            if (iVar4 != 1) goto LAB_00549853;
            goto LAB_00549784;
          }
          piVar2 = *(int **)(*piVar6 + 0xca4);
          if (*(char *)((int)piVar2 + 0x25) == '\x01') {
            uVar5 = (DAT_0080229c | DAT_00802298) & piVar2[1];
            if (uVar5 == DAT_00802298) {
              param_1 = (undefined *)0xbf800000;
            }
            else if (uVar5 == DAT_0080229c) {
              param_1 = (undefined *)0x3f800000;
            }
            else {
              param_1 = (undefined *)0x0;
            }
            uVar5 = (DAT_00802294 | DAT_00802290) & piVar2[1];
            if (uVar5 == DAT_00802290) {
              fVar3 = -1.0;
            }
            else if (uVar5 == DAT_00802294) {
              fVar3 = 1.0;
            }
            else {
              fVar3 = 0.0;
            }
          }
          else {
            param_1 = (undefined *)(((float)*(byte *)(*piVar2 + 0x92) - 127.5) * 0.007843138);
            fVar3 = ((float)*(byte *)(*piVar2 + 0x93) - 127.5) * 0.007843138;
          }
          *(float *)(puVar7 + 0x204) =
               (float)((DAT_008021c0 * 0x10000) / 0x168) * fVar3 + *(float *)(puVar7 + 0x204);
        }
        iStack_4 = (iVar1 * 0x10000) / 0x168;
        *(float *)(puVar7 + 0x208) = (float)iStack_4 * (float)param_1 + *(float *)(puVar7 + 0x208);
        local_c = local_c + 1.0;
      }
LAB_00549853:
      if (1.0 < local_c) {
        *(float *)(puVar7 + 0x204) = (1.0 / local_c) * *(float *)(puVar7 + 0x204);
        *(float *)(puVar7 + 0x208) = (1.0 / local_c) * *(float *)(puVar7 + 0x208);
      }
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < 0x93d7f8);
  }
  fVar3 = (float)((DAT_008021c0 * 0x10000) / 0x168) * _DAT_00925018;
  fVar8 = (float10)FUN_0054fad0(*(undefined4 *)(puVar7 + 0x20c),*(undefined4 *)(puVar7 + 0x204),
                                fVar3 + fVar3);
  iVar1 = DAT_008021c4;
  *(float *)(puVar7 + 0x20c) = (float)fVar8;
  fVar3 = (float)((iVar1 * 0x10000) / 0x168) * _DAT_00925018;
  fVar8 = (float10)FUN_0054fad0(*(undefined4 *)(puVar7 + 0x210),*(undefined4 *)(puVar7 + 0x208),
                                fVar3 + fVar3);
  *(float *)(puVar7 + 0x210) = (float)fVar8;
  fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(puVar7 + 0x214),*(undefined4 *)(puVar7 + 0x20c),
                                0x40400000);
  *(float *)(puVar7 + 0x214) = (float)fVar8;
  fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(puVar7 + 0x218),*(undefined4 *)(puVar7 + 0x210),
                                0x40400000);
  *(float *)(puVar7 + 0x218) = (float)fVar8;
  return;
}


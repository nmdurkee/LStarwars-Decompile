/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558070; label: FUN_00558070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00558070(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int *local_24;
  int local_20;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((((param_1 != 0) && (param_2 != 0)) &&
      (piVar3 = *(int **)(param_1 + 0x2ac8), piVar3 != (int *)0x0)) && (*piVar3 != 0)) {
    *(undefined2 *)(param_2 + 0xc) = 0;
    iVar1 = *piVar3 + DAT_00802644 * 0x14;
    local_24 = *(int **)(iVar1 + 0xc);
    local_20 = 0;
    if (0 < *(int *)(*piVar3 + 4 + DAT_00802644 * 0x14)) {
      do {
        iVar4 = *local_24;
        uVar8 = *(uint *)(iVar4 + 0x94);
        uVar5 = *(undefined4 *)(iVar4 + 0x38);
        *(undefined4 *)(iVar4 + 0x38) = 0;
        if ((((uVar8 & 2) != 0) && ((uVar8 & 5) != 0)) &&
           ((*(int *)(iVar4 + 0x34) != 0 &&
            (((uVar8 & 0x100) == 0 && ((*(byte *)(iVar4 + 0x9c) & 0x80) == 0)))))) {
          if (*(byte *)(iVar4 + 0x91) == 7) {
            if ((uVar8 & 8) == 0) {
              if (*(char *)(iVar4 + 0x90) == '\x01') {
                *(undefined4 *)(iVar4 + 0x48) = 0xbf800000;
              }
              else {
                *(undefined4 *)(iVar4 + 0x48) = 0;
              }
            }
            else {
              *(undefined4 *)(iVar4 + 0x38) = uVar5;
            }
            if (*(float *)(iVar4 + 0x48) == 0.0) {
LAB_0055817f:
              FUN_00557940(iVar4);
            }
            else {
              FUN_00557960();
            }
          }
          else {
            uVar8 = uVar8 >> 2 & 1;
            if ((uVar8 == 0) || (*(float *)(iVar4 + 0x48) == 0.0)) {
              if ((uVar8 != 0) && (*(float *)(iVar4 + 0x48) == 0.0)) goto LAB_0055817f;
              if ((code *)(&PTR_FUN_00802684)[*(byte *)(iVar4 + 0x91)] != (code *)0x0) {
                (*(code *)(&PTR_FUN_00802684)[*(byte *)(iVar4 + 0x91)])(iVar4);
              }
            }
            else {
              FUN_00557960(iVar4);
            }
          }
          if ((*(ushort *)(*(int *)(iVar4 + 0x34) + 10) & 7) != 0) {
            FUN_00557690();
            if ((*(byte *)(iVar4 + 0x9c) & 0x20) != 0) {
              for (puVar6 = *(undefined4 **)(*(int *)(iVar4 + 0x34) + 0x18);
                  puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {
                if ((*(byte *)puVar6[9] & 2) != 0) {
                  FUN_0058b3b0(puVar6 + 1,*(undefined2 *)((byte *)puVar6[9] + 2));
                }
              }
            }
            if (0.0 <= *(float *)(iVar4 + 0x48)) {
              if ((*(short *)(iVar4 + 0x8c) != -1) &&
                 ((*(int *)(*(int *)(iVar4 + 0x34) + 0xc) == 0 ||
                  (iVar7 = FUN_00650ef0((int)*(short *)(iVar4 + 0x8c)), iVar7 != 0)))) {
                sVar2 = *(short *)(iVar4 + 0x8c);
                goto LAB_00558264;
              }
            }
            else if ((*(short *)(iVar4 + 0x8e) != -1) &&
                    ((*(int *)(*(int *)(iVar4 + 0x34) + 0xc) == 2 ||
                     (iVar7 = FUN_00650ef0((int)*(short *)(iVar4 + 0x8e)), iVar7 != 0)))) {
              sVar2 = *(short *)(iVar4 + 0x8e);
LAB_00558264:
              FUN_005478a0((int)sVar2,iVar4 + 0x28,0,0);
            }
          }
          iVar7 = *(int *)(iVar4 + 0x34);
          if (*(int *)(iVar7 + 0xc) == 2) {
            *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xffffffbf;
          }
          if ((((*(char *)(iVar4 + 0x90) == '\0') || (*(char *)(iVar4 + 0x90) == '\x03')) ||
              ((*(byte *)(iVar4 + 0x68) & 0x80) != 0)) &&
             ((((*(byte *)(iVar7 + 10) & 2) != 0 || (*(char *)(iVar7 + 9) == '\0')) &&
              (*(int *)(iVar7 + 0xc) == 2)))) {
            if (*(short *)(iVar4 + 0x88) == -1) {
              if (*(short *)(iVar4 + 0x8a) != 0) goto LAB_0055833a;
            }
            else {
              if ((*(uint *)(iVar4 + 0x68) & 0x200) == 0) {
                FUN_0056a8c0(param_1,(int)*(short *)(iVar4 + 0x88),iVar4 + 0x28);
              }
              else if (iVar7 != 0) {
                for (puVar6 = *(undefined4 **)(iVar7 + 0x18); puVar6 != (undefined4 *)0x0;
                    puVar6 = (undefined4 *)*puVar6) {
                  iVar7 = FUN_005cf9e0(puVar6 + 1);
                  if (iVar7 != 0) {
                    FUN_0056a8c0(param_1,(int)*(short *)(iVar4 + 0x88),iVar7);
                  }
                }
              }
              FUN_005a15e0(*(undefined4 *)(iVar4 + 0x34),0);
              *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) | 0x80;
LAB_0055833a:
              if ((*(short *)(iVar4 + 0x8a) != 0) &&
                 (((*(byte *)(iVar4 + 0x9c) & 1) == 0 || ((*(byte *)(iVar4 + 0x68) & 0x80) != 0))))
              {
                FUN_005b37d0(local_c,iVar4 + 0x28,iVar4 + 0x70);
                FUN_005b35a0(local_18,&DAT_00802500,*(undefined2 *)(iVar4 + 0x80));
                FUN_005b3620(local_18,local_18,*(undefined2 *)(iVar4 + 0x82));
                FUN_0046d270(*(undefined2 *)(iVar4 + 0x8a),0,0,0,local_c,local_18,0x40000000,
                             0xffffffff,*(undefined4 *)(iVar4 + 0x7c),0x49f42400,0,1,0);
                *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) | 1;
              }
            }
            if (*(char *)(iVar4 + 0x90) == '\x03') {
              FUN_005a1230(*(undefined4 *)(iVar4 + 0x34));
              FUN_00557690();
              FUN_005a15e0(*(undefined4 *)(iVar4 + 0x34),1);
              *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xffffff7f;
            }
          }
          if (((*(byte *)(iVar4 + 0x9c) & 0x80) == 0) && ((*(uint *)(iVar4 + 0x68) & 0x1800) != 0))
          {
            *(int **)(*(int *)(param_2 + 4) + (uint)*(ushort *)(param_2 + 0xc) * 4) = local_24;
            *(short *)(param_2 + 0xc) = *(short *)(param_2 + 0xc) + 1;
          }
          *(uint *)(iVar4 + 0x94) = *(uint *)(iVar4 + 0x94) & 0xfffffff3;
          *(undefined4 *)(iVar4 + 0x48) = 0x3f800000;
        }
        local_24 = local_24 + 2;
        local_20 = local_20 + 1;
      } while (local_20 < *(int *)(iVar1 + 4));
    }
    DAT_0093b1e0 = 0;
  }
  return;
}


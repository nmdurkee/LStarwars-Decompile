/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59eeb0; label: FUN_0059eeb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059eeb0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int local_418;
  undefined4 *local_414;
  undefined4 local_410;
  int local_40c;
  undefined4 local_408;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_418;
  puVar4 = (undefined4 *)0x0;
  local_40c = param_1;
  if (DAT_00956428 != 0) {
    *(undefined1 *)(DAT_00956428 + 3) = 2;
    iVar2 = FUN_004fc5b0(param_1);
    while (iVar2 != 0) {
      FUN_004f7fb0(param_1);
      iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
      if (iVar2 == 0) break;
      uVar7 = *(undefined4 *)(param_1 + 0x510);
      if (DAT_00956414 != (int *)0x0) {
        iVar2 = *DAT_00956414;
        piVar5 = DAT_00956414;
        while (iVar2 != 0) {
          iVar2 = FUN_004f8b10(uVar7,iVar2);
          if (iVar2 == 0) {
            puVar3 = (undefined4 *)FUN_00559610(DAT_00956418,DAT_0095641c,0x10);
            if (puVar3 != (undefined4 *)0x0) {
              *puVar3 = 0;
              puVar3[1] = 0;
              puVar3[2] = 0;
              puVar3[3] = 0;
              if (puVar4 == (undefined4 *)0x0) {
                *(undefined4 **)(DAT_00956428 + 0xc) = puVar3;
              }
              else {
                *puVar4 = puVar3;
              }
              puVar3[3] = piVar5;
              iVar6 = 0;
              local_414 = puVar3;
              iVar2 = FUN_004f7fb0(param_1);
              puVar4 = local_414;
              if (iVar2 != 0) {
                puVar8 = local_404;
                do {
                  iVar2 = FUN_004f20f0(*(undefined4 *)(param_1 + 0x510),&DAT_0075a204);
                  if (iVar2 == 0) {
                    FUN_004fc5b0(param_1);
                  }
                  else {
                    FUN_004f1f10(puVar8,*(undefined4 *)(param_1 + 0x510));
                    iVar6 = iVar6 + 1;
                    puVar8 = puVar8 + 0x40;
                  }
                  iVar2 = FUN_004f7fb0(param_1);
                } while (iVar2 != 0);
                puVar4 = local_414;
                local_418 = iVar6;
                if (iVar6 != 0) {
                  iVar2 = FUN_00559610(DAT_00956418,DAT_0095641c,iVar6 * 4);
                  puVar3[1] = iVar2;
                  puVar4 = local_414;
                  if (iVar2 != 0) {
                    iVar2 = 0;
                    puVar3[2] = iVar6;
                    if (0 < iVar6) {
                      puVar8 = local_404;
                      do {
                        uVar7 = 0;
                        local_410 = DAT_0095641c;
                        local_408 = DAT_00956418;
                        if ((puVar8 != (undefined1 *)0x0) &&
                           (iVar6 = FUN_004f1ff0(puVar8), iVar6 != 0)) {
                          uVar7 = FUN_00559610(local_408,local_410,iVar6 + 1);
                          FUN_004f1f10(uVar7,puVar8);
                        }
                        *(undefined4 *)(puVar3[1] + iVar2 * 4) = uVar7;
                        iVar2 = iVar2 + 1;
                        puVar8 = puVar8 + 0x40;
                        puVar4 = local_414;
                        param_1 = local_40c;
                      } while (iVar2 < local_418);
                    }
                  }
                }
              }
            }
            break;
          }
          piVar1 = piVar5 + 2;
          piVar5 = piVar5 + 2;
          iVar2 = *piVar1;
        }
      }
      iVar2 = FUN_004fc5b0(param_1);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_418);
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x692830; label: FUN_00692830
 */

void FUN_00692830(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  iVar5 = 0;
  local_28 = param_1;
  iVar2 = 1;
  if (1 < DAT_02962098) {
    do {
      if (*(int *)(DAT_0296209c + iVar2 * 4) != 0) {
        iVar1 = *(int *)(DAT_0296209c + iVar2 * 4);
        if (DAT_0292118b == '\x01') {
          if (*(char *)(iVar1 + 0x10) != '\x01') goto LAB_00692893;
          bVar6 = *(char *)(iVar1 + 0x11) == DAT_008109cc;
        }
        else {
          bVar6 = *(char *)(iVar1 + 0x10) == DAT_0292118b;
        }
        if (bVar6) {
          iVar5 = iVar5 + 1;
        }
      }
LAB_00692893:
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_02962098);
  }
  _sprintf(local_24,"Particle Types (%d)",iVar5);
  DAT_0292fd48 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_00664900,local_24);
  if (DAT_0292fd48 != 0) {
    iVar5 = 1;
    bVar6 = false;
    iVar2 = DAT_0296209c;
    if (1 < DAT_02962098) {
      do {
        if (*(int *)(iVar2 + iVar5 * 4) != 0) {
          iVar1 = *(int *)(iVar2 + iVar5 * 4);
          if (DAT_0292118b == '\x01') {
            if (*(char *)(iVar1 + 0x10) != '\x01') goto LAB_006929bc;
            bVar7 = *(char *)(iVar1 + 0x11) == DAT_008109cc;
          }
          else {
            bVar7 = *(char *)(iVar1 + 0x10) == DAT_0292118b;
          }
          if (bVar7) {
            bVar7 = false;
            piVar3 = &DAT_02924b60;
            do {
              if (((*piVar3 != -1) && (*piVar3 != 99999)) && (piVar3[-1] == iVar5)) {
                bVar7 = true;
                break;
              }
              piVar3 = piVar3 + 0x16;
            } while ((int)piVar3 < 0x292fb60);
            bVar8 = DAT_00810ad8 == iVar5;
            if (bVar7) {
              uVar4 = FUN_00627b80(iVar5,&DAT_008109d8,bVar8,1,&LAB_006638a0,iVar1);
            }
            else {
              uVar4 = FUN_00627b80(iVar5,&DAT_008109f8,bVar8,1,&LAB_006638a0,iVar1);
            }
            FUN_00618e10(DAT_0292fd48,uVar4);
            iVar2 = DAT_0296209c;
            if (bVar8) {
              *(undefined4 *)(DAT_0292fd48 + 8) = DAT_02900c84;
              bVar6 = true;
              iVar2 = DAT_0296209c;
            }
          }
        }
LAB_006929bc:
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_02962098);
    }
    FUN_00619060(DAT_0292fd48);
    uVar4 = FUN_00627a80(1,&DAT_008109d8,0,0,&LAB_00692150,"Add Effect");
    FUN_00618e50(DAT_0292fd48,uVar4);
    iVar2 = local_28;
    FUN_006279b0(local_28,DAT_0292fd48);
    *(int *)(DAT_0292fd48 + 0x14) = *(int *)(iVar2 + 0x14) + 10;
    *(int *)(DAT_0292fd48 + 0x18) = *(int *)(iVar2 + 0x18) + 0x28;
    if (bVar6) {
      *(undefined4 *)(DAT_0292fd48 + 0xc) = *(undefined4 *)(DAT_0292fd48 + 8);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}


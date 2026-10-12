/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697bc0; label: FUN_00697bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00697bc0(void)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined1 local_20c [260];
  char local_108 [260];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_20c;
  do {
    WaitForSingleObject(DAT_02972c24,0xffffffff);
    if (DAT_02972c2c != '\0') break;
    if (DAT_02972bf4 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_02972bb0);
      iVar6 = 0;
      if (0 < DAT_02972be4) {
        iVar5 = 0;
        iVar4 = 0;
        do {
          if (DAT_02972c2c != '\0') break;
          bVar7 = (*(ushort *)(DAT_02972bf4 + ((int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4) * 2) &
                  (ushort)(1 << ((byte)iVar6 & 0xf))) != 0;
          if (DAT_02973954 == 0) {
            cVar3 = '\0';
          }
          else {
            cVar3 = *(char *)(iVar4 + 0x404 + DAT_02973954);
          }
          if (bVar7 != (bool)cVar3) {
            if (bVar7) {
              if ((DAT_02973954 == 0) || (*(char *)(iVar4 + 0x405 + DAT_02973954) == '\0')) {
                FUN_004f6900(local_20c);
                _sprintf(local_108,"%s%s",local_20c,*(undefined4 *)(DAT_02972bc8 + iVar5));
                if (0xfff < *(int *)(DAT_02972bc8 + 0xc + iVar5)) {
                  uVar1 = *(undefined4 *)(DAT_02972bc8 + iVar5);
                  iVar2 = FUN_004f8b10(&DAT_0075eaf8,PTR_DAT_00810d94);
                  if (iVar2 == 0) {
                    FUN_00696fa0(uVar1,iVar6);
                  }
                  else {
                    FUN_00696a90(PTR_DAT_00810d94);
                  }
                  if ((DAT_02973954 != 0) && (*(char *)(iVar4 + 0x405 + DAT_02973954) != '\0')) {
                    FUN_00696ab0(iVar6);
                  }
                }
              }
            }
            else if (0xfff < *(int *)(DAT_02972bc8 + 0xc + iVar5)) {
              FUN_00696c90(iVar6);
            }
          }
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + 0x40c;
          iVar5 = iVar5 + 0x1c;
        } while (iVar6 < DAT_02972be4);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_02972bb0);
    }
  } while (DAT_02972c2c == '\0');
  DAT_02972c28 = 0;
  __security_check_cookie(local_4 ^ (uint)local_20c);
  return;
}


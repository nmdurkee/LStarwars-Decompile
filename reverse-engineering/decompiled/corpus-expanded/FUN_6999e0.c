/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x6999e0; label: FUN_006999e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006999e0(void)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  DWORD DVar4;
  undefined4 uVar5;
  MMRESULT MVar6;
  int in_ECX;
  int iVar7;
  uint local_1c;
  undefined1 auStack_14 [2];
  short sStack_12;
  int iStack_10;
  
  bVar3 = false;
  do {
    DVar4 = WaitForMultipleObjects(2,(HANDLE *)(in_ECX + 0x5c),0,0xffffffff);
    if (DVar4 == 0) {
      if (((-1 < *(int *)(in_ECX + 4)) &&
          (FUN_006992c0((uint)(*(int *)(in_ECX + 0x58) * *(int *)(in_ECX + 0x24)) >> 2,0),
          0 < *(int *)(in_ECX + 0x1d8))) && (*(int *)(in_ECX + 8) == 2)) {
        piVar2 = *(int **)(in_ECX + 0x54);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x48))(piVar2);
        }
        *(undefined4 *)(in_ECX + 8) = 0;
        if (*(UINT *)(in_ECX + 100) != 0) {
          timeKillEvent(*(UINT *)(in_ECX + 100));
        }
        *(undefined4 *)(in_ECX + 100) = 0;
      }
    }
    else if (DVar4 == 1) {
      ResetEvent(*(HANDLE *)(in_ECX + 0x60));
      iVar7 = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
      if (0 < *(int *)(in_ECX + 0x1b8)) {
        iVar1 = *(int *)(in_ECX + 0x1bc);
        local_1c = *(uint *)(in_ECX + 0x138 + iVar1 * 4);
        iVar7 = *(int *)(in_ECX + 0xb8 + iVar1 * 4);
        *(uint *)(in_ECX + 0x1bc) = iVar1 + 1U & 0x1f;
        *(int *)(in_ECX + 0x1b8) = *(int *)(in_ECX + 0x1b8) + -1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
      while (iVar7 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x88));
        switch(iVar7) {
        case 1:
          FUN_004f1f40(in_ECX + 0x2e5,in_ECX + 0x1e0,0x104);
          *(undefined4 *)(in_ECX + 0x3f0) = *(undefined4 *)(in_ECX + 0x3ec);
          if (*(int *)(in_ECX + 8) == 2) {
            if (*(UINT *)(in_ECX + 100) != 0) {
              timeKillEvent(*(UINT *)(in_ECX + 100));
            }
            piVar2 = *(int **)(in_ECX + 0x54);
            *(undefined4 *)(in_ECX + 100) = 0;
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 0x48))(piVar2);
            }
          }
          *(undefined4 *)(in_ECX + 0xc) = 0;
          *(undefined4 *)(in_ECX + 8) = 0;
          *(undefined4 *)(in_ECX + 0x1d8) = 0;
          *(undefined4 *)(in_ECX + 0x1c8) = 0;
          *(undefined4 *)(in_ECX + 0x1cc) = 0;
          *(undefined4 *)(in_ECX + 4) = 0xffffffff;
          (**(code **)(**(int **)(in_ECX + 0x1dc) + 0xc))();
          iVar7 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 4))(0,in_ECX + 0x2e5,auStack_14);
          if (-1 < iVar7) {
            if ((*(int *)(in_ECX + 0x20) != iStack_10) || (*(short *)(in_ECX + 0x1e) != sStack_12))
            {
              FUN_00699070(auStack_14);
            }
            *(undefined4 *)(in_ECX + 4) = 1;
          }
          break;
        case 2:
          if (*(int *)(in_ECX + 4) < 0) {
LAB_00699c5d:
            if (*(UINT *)(in_ECX + 100) != 0) {
              timeKillEvent(*(UINT *)(in_ECX + 100));
            }
            *(undefined4 *)(in_ECX + 100) = 0;
          }
          else if (*(int *)(in_ECX + 8) != 2) {
            *(undefined4 *)(in_ECX + 0x1d8) = 0;
            *(undefined4 *)(in_ECX + 0xc) = 0;
            *(undefined4 *)(in_ECX + 0x1c8) = 0;
            *(undefined4 *)(in_ECX + 0x1cc) = 0;
            *(undefined4 *)(in_ECX + 0x1d0) = 0;
            (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x18))();
            iVar7 = *(int *)(in_ECX + 0x58) * 1000;
            if (iVar7 < 2000) {
              iVar7 = 2000;
            }
            iVar1 = *(int *)(in_ECX + 0x24);
            *(undefined4 *)(in_ECX + 8) = 1;
            uVar5 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x20))
                              (*(undefined4 *)(in_ECX + 0x3f0));
            *(undefined4 *)(in_ECX + 0x1c8) = uVar5;
            piVar2 = *(int **)(in_ECX + 0x54);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 0x34))(piVar2,0);
            }
            FUN_006992c0((uint)(iVar1 * iVar7) / 1000,2);
            piVar2 = *(int **)(in_ECX + 0x54);
            if ((piVar2 == (int *)0x0) ||
               (iVar7 = (**(code **)(*piVar2 + 0x34))(piVar2,0), iVar7 < 0)) goto LAB_00699c5d;
            if ((local_1c & 2) == 0) {
              iVar7 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x30))
                                (*(int **)(in_ECX + 0x54),0,0,1);
              if (iVar7 < 0) goto LAB_00699c5d;
              *(undefined4 *)(in_ECX + 0xc) = 1;
              *(undefined4 *)(in_ECX + 8) = 2;
              *(uint *)(in_ECX + 0x1d0) = local_1c;
              FUN_006998a0();
            }
            else {
              *(undefined4 *)(in_ECX + 8) = 3;
              *(uint *)(in_ECX + 0x1d0) = local_1c;
              FUN_006998a0();
            }
          }
          break;
        case 3:
          if (*(UINT *)(in_ECX + 100) != 0) {
            timeKillEvent(*(UINT *)(in_ECX + 100));
          }
          piVar2 = *(int **)(in_ECX + 0x54);
          *(undefined4 *)(in_ECX + 100) = 0;
          if ((piVar2 != (int *)0x0) && (iVar7 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar7))
          {
            *(undefined4 *)(in_ECX + 0x1cc) = 0;
            FUN_006992c0(*(int *)(in_ECX + 0x58) * *(int *)(in_ECX + 0x24),3);
          }
          *(undefined4 *)(in_ECX + 8) = 0;
          break;
        case 4:
          if (*(int *)(in_ECX + 8) == 2) {
            if (*(UINT *)(in_ECX + 100) != 0) {
              timeKillEvent(*(UINT *)(in_ECX + 100));
            }
            piVar2 = *(int **)(in_ECX + 0x54);
            *(undefined4 *)(in_ECX + 100) = 0;
            if ((piVar2 != (int *)0x0) &&
               (iVar7 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar7)) {
              *(undefined4 *)(in_ECX + 8) = 3;
            }
          }
          break;
        case 5:
          if (((*(int *)(in_ECX + 8) == 3) &&
              (piVar2 = *(int **)(in_ECX + 0x54), piVar2 != (int *)0x0)) &&
             (iVar7 = (**(code **)(*piVar2 + 0x30))(piVar2,0,0,1), -1 < iVar7)) {
            *(undefined4 *)(in_ECX + 8) = 2;
            *(undefined4 *)(in_ECX + 0xc) = 1;
            if (*(UINT *)(in_ECX + 100) != 0) {
              timeKillEvent(*(UINT *)(in_ECX + 100));
            }
            MVar6 = timeSetEvent(500,100,*(LPTIMECALLBACK *)(in_ECX + 0x5c),0,0x21);
            *(MMRESULT *)(in_ECX + 100) = MVar6;
          }
          break;
        case 6:
          *(undefined4 *)(in_ECX + 0x68) = 0;
          bVar3 = true;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x88));
        iVar7 = 0;
        EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
        if (0 < *(int *)(in_ECX + 0x1b8)) {
          iVar1 = *(int *)(in_ECX + 0x1bc);
          local_1c = *(uint *)(in_ECX + 0x138 + iVar1 * 4);
          iVar7 = *(int *)(in_ECX + 0xb8 + iVar1 * 4);
          *(uint *)(in_ECX + 0x1bc) = iVar1 + 1U & 0x1f;
          *(int *)(in_ECX + 0x1b8) = *(int *)(in_ECX + 0x1b8) + -1;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
        if ((*(int *)(in_ECX + 0x14) != *(int *)(in_ECX + 0x10)) || (*(int *)(in_ECX + 0x14) == 1))
        {
          EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
          if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
            (**(code **)(**(int **)(in_ECX + 0x54) + 0x3c))
                      (*(undefined4 *)(in_ECX + 0x54),*(undefined4 *)(in_ECX + 0x10));
            *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x10);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
        }
      }
    }
    if ((*(int *)(in_ECX + 0x14) != *(int *)(in_ECX + 0x10)) || (*(int *)(in_ECX + 0x14) == 1)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
      if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 0x54) + 0x3c))
                  (*(undefined4 *)(in_ECX + 0x54),*(undefined4 *)(in_ECX + 0x10));
        *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x10);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
    }
    if (bVar3) {
      return 0;
    }
  } while( true );
}


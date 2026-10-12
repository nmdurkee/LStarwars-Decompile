/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x6998f0; label: FUN_006998f0
 */

void FUN_006998f0(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  if (in_ECX != (int *)0x0) {
    if (*in_ECX != 0) {
      if (in_ECX[0xfd] != 0) {
        FUN_00699840();
      }
      if (*in_ECX != 0) {
        FUN_00699180(3,0);
      }
      FUN_00699180(6,0);
      iVar1 = in_ECX[0x1a];
      while (iVar1 != 0) {
        Sleep(10);
        iVar1 = in_ECX[0x1a];
      }
    }
    if ((undefined4 *)in_ECX[0x77] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x77])(1);
    }
    in_ECX[0x77] = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x28));
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x22));
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x1c));
    if ((HANDLE)in_ECX[0x18] != (HANDLE)0xffffffff) {
      CloseHandle((HANDLE)in_ECX[0x18]);
    }
    if ((HANDLE)in_ECX[0x17] != (HANDLE)0xffffffff) {
      CloseHandle((HANDLE)in_ECX[0x17]);
    }
    in_ECX[0x18] = -1;
    in_ECX[0x17] = -1;
    if (in_ECX[0x19] != 0) {
      timeKillEvent(in_ECX[0x19]);
    }
    piVar2 = (int *)in_ECX[0x15];
    in_ECX[0x19] = 0;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    in_ECX[0x15] = 0;
    *in_ECX = 0;
  }
  return;
}


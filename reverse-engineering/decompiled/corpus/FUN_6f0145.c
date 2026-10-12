/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6f0145; label: FUN_006f0145
 */

int FUN_006f0145(int param_1)

{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  
  pvVar1 = TlsGetValue(DAT_00829ab8);
  if ((pvVar1 != (LPVOID)0x0) && (DAT_00829ab4 != -1)) {
    iVar3 = DAT_00829ab4;
    pcVar2 = TlsGetValue(DAT_00829ab8);
    iVar3 = (*pcVar2)(iVar3);
    if (iVar3 != 0) {
      pFVar4 = *(FARPROC *)(iVar3 + 0x1f8);
      goto LAB_006f019f;
    }
  }
  hModule = GetModuleHandleA("KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    return param_1;
  }
  iVar3 = FUN_006f00d9();
  if (iVar3 == 0) {
    return param_1;
  }
  pFVar4 = GetProcAddress(hModule,"EncodePointer");
LAB_006f019f:
  if (pFVar4 != (FARPROC)0x0) {
    param_1 = (*pFVar4)(param_1);
  }
  return param_1;
}


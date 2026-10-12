/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6eeac7; label: ___report_gsfailure
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___report_gsfailure(void)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 unaff_retaddr;
  UINT uExitCode;
  undefined4 local_32c;
  undefined4 local_328;
  
  _DAT_0297c328 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_0297c32c = &stack0x00000004;
  _DAT_0297c268 = 0x10001;
  _DAT_0297c210 = 0xc0000409;
  _DAT_0297c214 = 1;
  local_32c = DAT_00829570;
  local_328 = DAT_00829574;
  _DAT_0297c21c = unaff_retaddr;
  _DAT_0297c2f4 = in_GS;
  _DAT_0297c2f8 = in_FS;
  _DAT_0297c2fc = in_ES;
  _DAT_0297c300 = in_DS;
  _DAT_0297c304 = unaff_EDI;
  _DAT_0297c308 = unaff_ESI;
  _DAT_0297c30c = unaff_EBX;
  _DAT_0297c310 = in_EDX;
  _DAT_0297c314 = in_ECX;
  _DAT_0297c318 = in_EAX;
  _DAT_0297c31c = unaff_EBP;
  DAT_0297c320 = unaff_retaddr;
  _DAT_0297c324 = in_CS;
  _DAT_0297c330 = in_SS;
  DAT_0297c260 = IsDebuggerPresent();
  FUN_006f8568(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_00777e80);
  if (DAT_0297c260 == 0) {
    FUN_006f8568(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}


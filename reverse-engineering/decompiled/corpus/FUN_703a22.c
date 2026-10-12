/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703a22; label: DName::DName
 */

/* Library Function - Single Match
    public: __thiscall DName::DName(unsigned __int64)
   
   Library: Visual Studio 2005 Release */

void __thiscall DName::DName(DName *this,__uint64 param_1)

{
  char extraout_CL;
  char *pcVar1;
  char local_d [5];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)this = 0;
  *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffff000;
  pcVar1 = local_d + 1;
  local_d[1] = 0;
  do {
    pcVar1 = pcVar1 + -1;
    param_1 = __aulldvrm(param_1,10,0);
    *pcVar1 = extraout_CL + '0';
  } while (param_1 != 0);
  doPchar(this,pcVar1,(int)(local_d + (1 - (int)pcVar1)));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


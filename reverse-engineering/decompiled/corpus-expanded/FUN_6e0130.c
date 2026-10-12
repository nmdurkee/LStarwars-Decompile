/* Ghidra pseudocode, not original source.
 * ev_887128996bbafa307d3b1e0fcc7dc6d1e8180ed805c49046b1ad40b6cc957347
 * Entry: 0x6e0130; label: FUN_006e0130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e0130(int param_1,char *param_2)

{
  int iVar1;
  
  if (param_2 != (char *)0x0) {
    _vsprintf(&DAT_0297b698,param_2,&stack0x0000000c);
  }
  _sprintf(&DAT_0297ae98,
           "Important. Do not ignore!\n\n%s\n\n(Your application has generated an error message)\n\n"
           ,&DAT_0297b698);
  FUN_006dff40(&DAT_0297ae98);
  iVar1 = MessageBoxA(DAT_00924864,&DAT_0297ae98,"Nu2Api Runtime Error!",0x12);
  if (iVar1 != 3) {
    if (iVar1 == 4) {
      DebugBreak();
    }
    _sprintf(&DAT_0297ae98,"NUERROR: %s\r\n",&DAT_0297b698);
    OutputDebugStringA(&DAT_0297ae98);
    if ((*(char *)(param_1 + 0x504) != '\0') && (*(int *)(param_1 + 0x500) != 0)) {
      FUN_004f0750(*(int *)(param_1 + 0x500),&DAT_0297ae98);
    }
    return;
  }
  _raise(0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


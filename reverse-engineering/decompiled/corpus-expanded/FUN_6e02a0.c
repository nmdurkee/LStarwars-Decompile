/* Ghidra pseudocode, not original source.
 * ev_887128996bbafa307d3b1e0fcc7dc6d1e8180ed805c49046b1ad40b6cc957347
 * Entry: 0x6e02a0; label: FUN_006e02a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e02a0(undefined4 param_1,undefined4 param_2,char *param_3)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (param_3 != (char *)0x0) {
    _vsprintf(&DAT_0297b698,param_3,&stack0x00000010);
  }
  uVar1 = FUN_007390a6(param_2);
  uVar1 = FUN_007158f6(param_2,uVar1);
  _sprintf(&DAT_0297ae98,"NUD3DWARNING: %s, DirectDescription: %s, %s\r\n",&DAT_0297b698,uVar1);
  OutputDebugStringA(&DAT_0297ae98);
  if ((*(char *)(unaff_ESI + 0x504) != '\0') && (*(int *)(unaff_ESI + 0x500) != 0)) {
    FUN_004f0750(*(int *)(unaff_ESI + 0x500),&DAT_0297ae98);
  }
  return;
}


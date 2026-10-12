/* Ghidra pseudocode, not original source.
 * ev_887128996bbafa307d3b1e0fcc7dc6d1e8180ed805c49046b1ad40b6cc957347
 * Entry: 0x6e01f0; label: FUN_006e01f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e01f0(int param_1,char *param_2)

{
  if (param_2 != (char *)0x0) {
    _vsprintf(&DAT_0297b698,param_2,&stack0x0000000c);
  }
  _sprintf(&DAT_0297ae98,"NUWARNING: %s\r\n",&DAT_0297b698);
  OutputDebugStringA(&DAT_0297ae98);
  if ((*(char *)(param_1 + 0x504) != '\0') && (*(int *)(param_1 + 0x500) != 0)) {
    FUN_004f0750(*(int *)(param_1 + 0x500),&DAT_0297ae98);
  }
  return;
}


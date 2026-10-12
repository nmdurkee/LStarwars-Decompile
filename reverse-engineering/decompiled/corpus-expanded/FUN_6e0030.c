/* Ghidra pseudocode, not original source.
 * ev_887128996bbafa307d3b1e0fcc7dc6d1e8180ed805c49046b1ad40b6cc957347
 * Entry: 0x6e0030; label: FUN_006e0030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e0030(int param_1,char *param_2)

{
  if (param_2 != (char *)0x0) {
    _vsprintf(&DAT_0297b698,param_2,&stack0x0000000c);
  }
  _sprintf(&DAT_0297ae98,"NUDEBUG: %s",&DAT_0297b698);
  if (*(char *)(param_1 + 1) != '\0') {
    OutputDebugStringA(&DAT_0297ae98);
  }
  return;
}


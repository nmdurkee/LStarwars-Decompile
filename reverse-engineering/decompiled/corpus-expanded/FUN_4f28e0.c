/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f28e0; label: FUN_004f28e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004f28e0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  float local_8;
  float local_4;
  
  cVar1 = *param_1;
  local_8 = 0.0;
  pcVar2 = param_1 + 1;
  local_4 = 1.0;
  if (cVar1 == '-') {
    cVar1 = *pcVar2;
    local_4 = -1.0;
    pcVar2 = param_1 + 2;
  }
  while (('/' < cVar1 && (cVar1 < ':'))) {
    local_8 = local_8 * 10.0 + (float)(cVar1 + -0x30);
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  }
  if (cVar1 == '.') {
    cVar1 = *pcVar2;
    while (('/' < cVar1 && (pcVar2 = pcVar2 + 1, cVar1 < ':'))) {
      local_4 = local_4 * 10.0;
      local_8 = local_8 * 10.0 + (float)(cVar1 + -0x30);
      cVar1 = *pcVar2;
    }
  }
  return (float10)(local_8 / local_4);
}


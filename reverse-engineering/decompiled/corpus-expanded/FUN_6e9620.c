/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e9620; label: shortsort
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _shortsort
   
   Library: Visual Studio 2005 Release */

void __cdecl shortsort(undefined1 *param_1,undefined1 *param_2,int param_3,code *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  
  for (; puVar2 = param_1, puVar4 = param_1, param_1 < param_2; param_2 = param_2 + -param_3) {
    while (puVar4 = puVar4 + param_3, puVar4 <= param_2) {
      iVar3 = (*param_4)(puVar4,puVar2);
      if (0 < iVar3) {
        puVar2 = puVar4;
      }
    }
    if ((puVar2 != param_2) && (param_3 != 0)) {
      puVar4 = param_2;
      iVar3 = param_3;
      do {
        uVar1 = puVar4[(int)puVar2 - (int)param_2];
        puVar4[(int)puVar2 - (int)param_2] = *puVar4;
        iVar3 = iVar3 + -1;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      } while (iVar3 != 0);
    }
  }
  return;
}


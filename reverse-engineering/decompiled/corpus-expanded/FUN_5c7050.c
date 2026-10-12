/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c7050; label: FUN_005c7050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005c7050(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(in_ECX + 0x710);
  uVar3 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      cVar2 = FUN_005c6dc0(param_1,param_2,iVar4);
      if (cVar2 != '\0') {
        uVar3 = uVar3 | 1 << ((byte)iVar4 & 0x1f);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return uVar3;
}


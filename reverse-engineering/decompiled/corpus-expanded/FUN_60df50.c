/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60df50; label: FUN_0060df50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060df50(undefined4 param_1)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = &PTR_FUN_0076a940;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  puVar1 = in_ECX + 0x10;
  iVar2 = 0x1d;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


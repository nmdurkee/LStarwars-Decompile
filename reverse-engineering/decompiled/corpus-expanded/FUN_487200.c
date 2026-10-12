/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x487200; label: FUN_00487200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00487200(void)

{
  int iVar1;
  undefined4 *in_ECX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xcd0) != 0) {
    if (in_ECX == (undefined4 *)0x0) {
      FUN_004871a0(*(int *)(unaff_ESI + 0xcd0),unaff_ESI + 0x5c);
    }
    else {
      *(undefined4 *)(unaff_ESI + 0x5c) = *in_ECX;
      *(undefined4 *)(unaff_ESI + 0x60) = in_ECX[1];
      *(undefined4 *)(unaff_ESI + 100) = in_ECX[2];
    }
    iVar1 = *(int *)(unaff_ESI + 0xcd0);
    *(undefined2 *)(unaff_ESI + 0x278) = 0;
    *(undefined2 *)(unaff_ESI + 0x27c) = 0;
    *(undefined2 *)(unaff_ESI + 0x27a) = *(undefined2 *)(iVar1 + 0x58);
    *(undefined2 *)(unaff_ESI + 0x58) = *(undefined2 *)(iVar1 + 0x58);
    *(undefined2 *)(unaff_ESI + 0x5a) = *(undefined2 *)(iVar1 + 0x58);
  }
  FUN_0055d2b0();
  return;
}


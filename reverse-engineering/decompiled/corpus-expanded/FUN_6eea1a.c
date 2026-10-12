/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6eea1a; label: __initp_misc_cfltcvt_tab
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __initp_misc_cfltcvt_tab
   
   Library: Visual Studio 2005 Release */

void __initp_misc_cfltcvt_tab(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    puVar1 = (undefined4 *)((int)&PTR_LAB_00829a80 + uVar3);
    uVar2 = FUN_006f0145(*puVar1);
    uVar3 = uVar3 + 4;
    *puVar1 = uVar2;
  } while (uVar3 < 0x28);
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef720; label: FUN_004ef720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef720(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = DAT_0088ab20;
  DAT_0088ab20 = 0;
  piVar2 = (int *)FUN_004eef40(param_1 + 0x10,".\\numem.c",0x73);
  DAT_0088ab20 = uVar1;
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_1;
    piVar2[1] = param_1;
    piVar2[2] = (int)(piVar2 + 4);
  }
  return;
}


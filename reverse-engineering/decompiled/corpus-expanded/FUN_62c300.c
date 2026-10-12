/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62c300; label: FUN_0062c300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0062c300(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_006e6b90();
  uVar3 = 0;
  if (0xffff < (int)uVar1) {
    uVar3 = uVar1 >> 0x10;
    uVar1 = uVar1 + uVar3 * -0x10000;
  }
  uVar2 = FUN_005b9e30();
  if (uVar2 >> 0x10 < uVar1) {
    uVar3 = uVar3 + 1;
  }
  return uVar3;
}


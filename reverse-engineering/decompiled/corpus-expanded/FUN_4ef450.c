/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef450; label: FUN_004ef450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_004ef450(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  
  puVar2 = DAT_0088ab18;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return (int *)0x0;
    }
    piVar1 = (int *)(puVar2[4] + 0x20 + (int)puVar2);
    uVar4 = 0xc;
    pcVar5 = s_MEMBLKHEADER_00800444;
    piVar3 = puVar2 + 5;
    do {
      if (*piVar3 != *(int *)pcVar5) goto LAB_004ef498;
      uVar4 = uVar4 - 4;
      pcVar5 = (char *)((int)pcVar5 + 4);
      piVar3 = piVar3 + 1;
    } while (3 < uVar4);
    if (uVar4 != 0) {
LAB_004ef498:
      if ((char)*piVar3 != (char)*(int *)pcVar5) goto LAB_004ef57e;
      if (uVar4 != 1) {
        if (*(char *)((int)piVar3 + 1) != *(char *)((int)pcVar5 + 1)) goto LAB_004ef57e;
        if (uVar4 != 2) {
          if (*(char *)((int)piVar3 + 2) != *(char *)((int)pcVar5 + 2)) {
LAB_004ef57e:
            piVar3 = (int *)FUN_004eedc0(puVar2,piVar1 + 3,puVar2[2]);
            return piVar3;
          }
          if ((uVar4 != 3) && (*(char *)((int)piVar3 + 3) != *(char *)((int)pcVar5 + 3)))
          goto LAB_004ef57e;
        }
      }
    }
    uVar4 = 0xc;
    pcVar5 = s_MEMBLKTAIL01_00800454;
    piVar3 = piVar1;
    do {
      if (*piVar3 != *(int *)pcVar5) goto LAB_004ef51b;
      uVar4 = uVar4 - 4;
      pcVar5 = (char *)((int)pcVar5 + 4);
      piVar3 = piVar3 + 1;
    } while (3 < uVar4);
    if (uVar4 != 0) {
LAB_004ef51b:
      if ((char)*piVar3 != (char)*(int *)pcVar5) goto LAB_004ef598;
      if (uVar4 != 1) {
        if (*(char *)((int)piVar3 + 1) != *(char *)((int)pcVar5 + 1)) goto LAB_004ef598;
        if (uVar4 != 2) {
          if (*(char *)((int)piVar3 + 2) != *(char *)((int)pcVar5 + 2)) {
LAB_004ef598:
            FUN_004eedc0(piVar1,piVar1 + 3,puVar2[2]);
            return piVar1;
          }
          if ((uVar4 != 3) && (*(char *)((int)piVar3 + 3) != *(char *)((int)pcVar5 + 3)))
          goto LAB_004ef598;
        }
      }
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


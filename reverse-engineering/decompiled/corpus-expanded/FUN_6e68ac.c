/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e68ac; label: __cfltcvt_init
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __cfltcvt_init
   
   Library: Visual Studio 2005 Release */

void __cfltcvt_init(void)

{
  PTR_LAB_00829a80 = __cfltcvt;
  PTR_LAB_00829a84 = &LAB_006ee09e;
  PTR_LAB_00829a88 = &LAB_006ee05c;
  PTR_LAB_00829a8c = &LAB_006ee090;
  PTR_LAB_00829a90 = &LAB_006ee006;
  PTR_LAB_00829a94 = __cfltcvt;
  PTR_LAB_00829a98 = __cfltcvt_l;
  PTR_LAB_00829a9c = __fassign_l;
  PTR_LAB_00829aa0 = __cropzeros_l;
  PTR_LAB_00829aa4 = __forcdecpt_l;
  return;
}


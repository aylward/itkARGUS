itk_module_test()

set(itkARGUSTests
  itkResampleImageUsingMapFilterTest.cxx
  )

CreateTestDriver(itkARGUS "${itkARGUS-Test_LIBRARIES}" "${itkARGUSTests}")

itk_add_test(NAME itkResampleImageUsingMapFilterTest
  COMMAND itkARGUSTestDriver
    --compare
    DATA{Baseline/itkResampleImageUsingMapFilterTestOutput.mha}
    ${ITK_TEST_OUTPUT_DIR}/itkResampleImageUsingMapFilterTestOutput.mha
  itkResampleImageUsingMapFilterTest
    ${ITK_TEST_OUTPUT_DIR}/itkResampleImageUsingMapFilterTestOutput.mha
  )

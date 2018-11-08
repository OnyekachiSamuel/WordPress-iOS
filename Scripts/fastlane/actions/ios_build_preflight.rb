module Fastlane
  module Actions
    class IosBuildPreflightAction < Action
      def self.run(params) 
        Action.sh("cd .. && rm -rf ~/Library/Developer/Xcode/DerivedData")
        
        # Check gems and pods are up to date. This will exit if it fails
        begin
          Action.sh("bundle check")
        rescue 
          UI.user_error!("You should run 'rake dependencies' to make sure gems are up to date")
          raise
        end

        Action.sh("rake dependencies:pod:clean")
        other_action.cocoapods()
      end

      #####################################################
      # @!group Documentation
      #####################################################

      def self.description
        "Clean the environment to ensure a safe build"
      end

      def self.details
        "Clean the environment to ensure a safe build"
      end

      def self.available_options
        
      end

      def self.output
        
      end

      def self.return_value
       
      end

      def self.authors
        ["loremattei"]
      end

      def self.is_supported?(platform)
        platform == :ios
      end
    end
  end
end
